/******************************************************************************
 *   Copyright (C) 2025 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2025 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include "R3BLosvsAlpideOnlineSpectra.h"
#include "R3BEventHeader.h"
#include "R3BAlpideHitData.h"
#include "R3BLogger.h"
#include "R3BLosHitData.h"
#include "R3BShared.h"

#include <FairLogger.h>
#include <FairRootManager.h>
#include <FairRunOnline.h>
#include <FairRuntimeDb.h>

#include <TCanvas.h>
#include <TFolder.h>
#include <TH2F.h>
#include <THttpServer.h>
#include <TVector3.h>

#include <TClonesArray.h>
#include <sstream>
#include <string>

R3BLosvsAlpideOnlineSpectra::R3BLosvsAlpideOnlineSpectra()
    : R3BLosvsAlpideOnlineSpectra("R3BLosvsAlpideOnlineSpectra", 1)
{
}

R3BLosvsAlpideOnlineSpectra::R3BLosvsAlpideOnlineSpectra(const TString& name, int iVerbose)
    : FairTask(name, iVerbose)
{
}

void R3BLosvsAlpideOnlineSpectra::SetParContainers()
{
    // Parameter Container
    // Reading amsStripCalPar from FairRuntimeDb
    FairRuntimeDb* rtdb = FairRuntimeDb::instance();
    R3BLOG_IF(fatal, !rtdb, "FairRuntimeDb not found");
}

InitStatus R3BLosvsAlpideOnlineSpectra::Init()
{
    R3BLOG(info, "");
    FairRootManager* mgr = FairRootManager::Instance();
    R3BLOG_IF(fatal, mgr == nullptr, "FairRootManager not found");

    fHeader = dynamic_cast<R3BEventHeader*>(mgr->GetObject("EventHeader."));
    R3BLOG_IF(fatal, fHeader == nullptr, "EventHeader. not found");

    // get access to Hit data
    fHitItemsLos = dynamic_cast<TClonesArray*>(mgr->GetObject("LosHit"));
    R3BLOG_IF(fatal, !fHitItemsLos, "LosHit not found");

    fHitItemsAlpide = dynamic_cast<TClonesArray*>(mgr->GetObject("AlpideHitData"));
    R3BLOG_IF(fatal, !fHitItemsAlpide, "AlpideHitData not found");

    // Create histograms for detectors
    cCLF = std::make_unique<TCanvas>("Los_vs_Alpide", "Los vs Alpide correlations", 10, 10, 500, 500);
    cCLF->Divide(4, 2);

    std::vector<std::string> hist_names;
    std::vector<std::string> hist_titles;
    std::vector<std::string> hist_xaxis_titles;
    std::vector<std::string> hist_yaxis_titles;

    std::vector<std::string> hist_names_max;
    std::vector<std::string> hist_titles_max;
    std::vector<std::string> hist_xaxis_titles_max;

    for (int i = 1; i <= 12; i++) // NOLINT
    {
        hist_names.push_back("fh2_Charge_Los_Alpide" + std::to_string(i));
        hist_titles.push_back("Charge: LOS vs Alpide-" + std::to_string(i));
        hist_yaxis_titles.push_back("ChargeZ in LOS");
        hist_xaxis_titles.push_back("ChargeZ in Alpide-" + std::to_string(i));

        hist_names_max.push_back("fh2_Charge_Los_Alpide" + std::to_string(i) + "_max");
        hist_titles_max.push_back("Charge: LOS vs Alpide-" + std::to_string(i) + "_max");
        hist_xaxis_titles_max.push_back("ChargeZ in Alpide-" + std::to_string(i) + " (max)");
    }

    for (size_t i = 0; i < hist_names.size(); i++)
    {
        cCLF->cd(i + 1);
        gPad->SetLogz();
        fh2_cor.push_back(R3B::root_owned<TH2F>(hist_names[i].c_str(), hist_titles[i].c_str(), 300, 0, 30, 300, 0, 30));
        fh2_cor[i]->GetXaxis()->SetTitle(hist_xaxis_titles[i].c_str());
        fh2_cor[i]->GetYaxis()->SetTitle(hist_yaxis_titles[i].c_str());
        fh2_cor[i]->GetYaxis()->SetTitleOffset(1.2);
        fh2_cor[i]->GetXaxis()->CenterTitle(true);
        fh2_cor[i]->GetYaxis()->CenterTitle(true);
        fh2_cor[i]->Draw("COLZ");
    }

    cCLF_max = std::make_unique<TCanvas>("Los_vs_Alpide_max", "Los vs Alpide (Max. charge) correlations", 10, 10, 500, 500);
    cCLF_max->Divide(4, 2);

    for (size_t i = 0; i < hist_names.size(); i++)
    {
        cCLF_max->cd(i + 1);
        gPad->SetLogz();
        fh2_cor_max.push_back(
            R3B::root_owned<TH2F>(hist_names_max[i].c_str(), hist_titles_max[i].c_str(), 300, 0, 30, 300, 0, 30));
        fh2_cor_max[i]->GetXaxis()->SetTitle(hist_xaxis_titles_max[i].c_str());
        fh2_cor_max[i]->GetYaxis()->SetTitle(hist_yaxis_titles[i].c_str());
        fh2_cor_max[i]->GetYaxis()->SetTitleOffset(1.2);
        fh2_cor_max[i]->GetXaxis()->CenterTitle(true);
        fh2_cor_max[i]->GetYaxis()->CenterTitle(true);
        fh2_cor_max[i]->Draw("COLZ");
    }

    // MAIN FOLDER-Mwpc-Alpide
    auto mainfol = new TFolder("Los_vs_Alpide", "Los vs Alpide info");

    if (fHitItemsLos && fHitItemsAlpide)
    {
        mainfol->Add(cCLF.get());
        mainfol->Add(cCLF_max.get());
    }

    auto run = FairRunOnline::Instance();
    run->GetHttpServer()->Register("", this);

    run->AddObject(mainfol);

    // Register command to reset histograms
    run->GetHttpServer()->RegisterCommand("Reset_Los_vs_Alpide", Form("/Objects/%s/->Reset_Histo()", GetName()));

    return kSUCCESS;
}

// -----   Public method ReInit   ----------------------------------------------
InitStatus R3BLosvsAlpideOnlineSpectra::ReInit()
{
    SetParContainers();
    // SetParameter();
    return kSUCCESS;
}

void R3BLosvsAlpideOnlineSpectra::Reset_Histo()
{
    R3BLOG(info, "");
    for (const auto& hist : fh2_cor)
    {
        hist->Reset();
    }
    for (const auto& hist : fh2_cor_max)
    {
        hist->Reset();
    }
}

void R3BLosvsAlpideOnlineSpectra::Exec(Option_t* /*option*/)
{
    if ((fTpat > 0) && (fHeader != nullptr) && ((fHeader->GetTpat() & fTpat) != fTpat))
        return;

    int nHitsLos = fHitItemsLos->GetEntriesFast();
    int nHitsFo = fHitItemsAlpide->GetEntriesFast();

    if (nHitsLos == 0 || nHitsFo == 0)
        return;

    double zcharge_los = 0;
    for (size_t ihit = 0; ihit < nHitsLos; ihit++)
    {
        auto hit = dynamic_cast<R3BLosHitData*>(fHitItemsLos->At(ihit));
        if (hit)
            zcharge_los = std::max(zcharge_los, hit->GetZ());
    }

    if (zcharge_los == 0)
        return;

    std::vector<double> max_zcharge_alpide(12, 0.0);
    for (size_t ihit = 0; ihit < nHitsFo; ihit++)
    {
        auto hit = dynamic_cast<R3BAlpideHitData*>(fHitItemsAlpide->At(ihit));
        double idet = hit->GetSensorId() - 1;
        if (idet < 0)
            continue;

        auto zcharge_alpide = hit->GetClusterSize();
        //max_zcharge_alpide[idet] = std::max(max_zcharge_alpide[idet], zcharge_alpide);

	if (max_zcharge_alpide[idet] < zcharge_alpide)

	     max_zcharge_alpide[idet] = zcharge_alpide;


        fh2_cor[idet]->Fill(zcharge_alpide, zcharge_los);
    }

    for (size_t i = 0; i < max_zcharge_alpide.size(); i++)
    {
        fh2_cor_max[i]->Fill(max_zcharge_alpide[i], zcharge_los);
    }
    fNEvents++;
}

void R3BLosvsAlpideOnlineSpectra::FinishEvent()
{
    if (fHitItemsLos)
    {
        fHitItemsLos->Clear();
    }
    if (fHitItemsAlpide)
    {
        fHitItemsAlpide->Clear();
    }
}

void R3BLosvsAlpideOnlineSpectra::FinishTask()
{
    // Write canvas for Hit data
    if (fHitItemsLos && fHitItemsAlpide)
    {
        for (const auto& hist : fh2_cor)
        {
            hist->Write();
        }
        for (const auto& hist : fh2_cor_max)
        {
            hist->Write();
        }
    }
}

ClassImp(R3BLosvsAlpideOnlineSpectra)
