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

#include "R3BMwpcvsAlpideOnlineSpectra.h"
#include "R3BEventHeader.h"
#include "R3BAlpideHitData.h"
#include "R3BLogger.h"
#include "R3BMwpcHitData.h"
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

R3BMwpcvsAlpideOnlineSpectra::R3BMwpcvsAlpideOnlineSpectra()
    : R3BMwpcvsAlpideOnlineSpectra("R3BMwpcvsAlpideOnlineSpectra", 1)
{
}

R3BMwpcvsAlpideOnlineSpectra::R3BMwpcvsAlpideOnlineSpectra(const TString& name, int iVerbose)
    : FairTask(name, iVerbose)
{
}

void R3BMwpcvsAlpideOnlineSpectra::SetParContainers()
{
    // Parameter Container
    // Reading amsStripCalPar from FairRuntimeDb
    FairRuntimeDb* rtdb = FairRuntimeDb::instance();
    R3BLOG_IF(fatal, !rtdb, "FairRuntimeDb not found");
}

InitStatus R3BMwpcvsAlpideOnlineSpectra::Init()
{
    R3BLOG(info, "");
    FairRootManager* mgr = FairRootManager::Instance();
    R3BLOG_IF(fatal, mgr == nullptr, "FairRootManager not found");

    fHeader = dynamic_cast<R3BEventHeader*>(mgr->GetObject("EventHeader."));
    R3BLOG_IF(fatal, fHeader == nullptr, "EventHeader. not found");

    // get access to Hit data
    fHitItemsMw = dynamic_cast<TClonesArray*>(mgr->GetObject("Mwpc0HitData"));
    R3BLOG_IF(fatal, !fHitItemsMw, "Mwpc0HitData not found");

    fHitItemsAlpide = dynamic_cast<TClonesArray*>(mgr->GetObject("AlpideHitData"));
    R3BLOG_IF(fatal, !fHitItemsAlpide, "AlpideHitData not found");

    // Create histograms for detectors
    cCMwF = std::make_unique<TCanvas>("Mwpc_vs_Alpide", "Mwpc vs Alpide correlations", 10, 10, 500, 500);
    cCMwF->Divide(2, 3);

    std::vector<std::string> hist_names;
    hist_names.push_back("fh2_MwpcX_Flex1X");
    hist_names.push_back("fh2_MwpcX_Flex1Y");
    hist_names.push_back("fh2_MwpcY_Flex2X");
    hist_names.push_back("fh2_MwpcY_Flex2Y");
    //hist_names.push_back("fh2_MwpcX_Alpide2Y");
    //hist_names.push_back("fh2_MwpcY_Alpide1X");

    std::vector<std::string> hist_titles;
    hist_titles.push_back("MwpcX vs Flex1X");
    hist_titles.push_back("MwpcY vs Flex1Y");
    hist_titles.push_back("MwpcX vs Flex2X");
    hist_titles.push_back("MwpcY vs Flex2Y");
    //hist_titles.push_back("MwpcX vs Alpide2Y");
    //hist_titles.push_back("MwpcY vs Alpide1X");

    std::vector<std::string> hist_xaxis_titles;
    hist_xaxis_titles.push_back("FLex1X [mm]");
    hist_xaxis_titles.push_back("Flex1Y [mm]");
    hist_xaxis_titles.push_back("Flex2X [mm]");
    hist_xaxis_titles.push_back("Flex2Y [mm]");
    //hist_xaxis_titles.push_back("MwpcX [mm]");
    //hist_xaxis_titles.push_back("Alpide1X [mm]");

    std::vector<std::string> hist_yaxis_titles;
    hist_yaxis_titles.push_back("MwpcX [mm]");
    hist_yaxis_titles.push_back("MwpcY [mm]");
    hist_yaxis_titles.push_back("MwpcX [mm]");
    hist_yaxis_titles.push_back("MwpcY [mm]");
    //hist_yaxis_titles.push_back("Alpide2Y [mm]");
    //hist_yaxis_titles.push_back("MwpcY [mm]");

    fh2_cor.resize(hist_names.size());
    fNbHist = hist_names.size();
    for (size_t i = 0; i < hist_names.size(); i++)
    {
        cCMwF->cd(i + 1);
        gPad->SetLogz();
        fh2_cor[i] = R3B::root_owned<TH2F>(hist_names[i].c_str(), hist_titles[i].c_str(), 400, -60, 60, 400, -60, 60);
        fh2_cor[i]->GetXaxis()->SetTitle(hist_xaxis_titles[i].c_str());
        fh2_cor[i]->GetYaxis()->SetTitle(hist_yaxis_titles[i].c_str());
        fh2_cor[i]->GetYaxis()->SetTitleOffset(1.2);
        fh2_cor[i]->GetXaxis()->CenterTitle(true);
        fh2_cor[i]->GetYaxis()->CenterTitle(true);
        fh2_cor[i]->Draw("COLZ");
    }

    // MAIN FOLDER-Mwpc-Alpide
    auto mainfol = new TFolder("Mwpc_vs_Alpide", "MWPC vs Alpide info");

    if (fHitItemsMw && fHitItemsAlpide)
    {
        mainfol->Add(cCMwF.get());
    }

    auto run = FairRunOnline::Instance();
    run->GetHttpServer()->Register("", this);

    run->AddObject(mainfol);

    // Register command to reset histograms
    run->GetHttpServer()->RegisterCommand("Reset_Mwpc_vs_Alpide", Form("/Objects/%s/->Reset_Histo()", GetName()));

    return kSUCCESS;
}

// -----   Public method ReInit   ----------------------------------------------
InitStatus R3BMwpcvsAlpideOnlineSpectra::ReInit()
{
    SetParContainers();
    // SetParameter();
    return kSUCCESS;
}

void R3BMwpcvsAlpideOnlineSpectra::Reset_Histo()
{
    R3BLOG(info, "");
    for (const auto& hist : fh2_cor)
    {
        hist->Reset();
    }
}

void R3BMwpcvsAlpideOnlineSpectra::Exec(Option_t* /*option*/)
{
    if ((fTpat > 0) && (fHeader) && ((fHeader->GetTpat() & fTpat) != fTpat))
        return;

    int nHitsMw = fHitItemsMw->GetEntriesFast();
    int nHitsAL = fHitItemsAlpide->GetEntriesFast();

    if (nHitsMw == 0 || nHitsAL == 0)
        return;

    std::vector<TVector3> VMw;
    for (size_t ihit = 0; ihit < nHitsMw; ihit++)
    {
        auto hit = dynamic_cast<R3BMwpcHitData*>(fHitItemsMw->At(ihit));
        VMw.push_back(TVector3(hit->GetX(), hit->GetY(), 0));
    }


    std::vector<double> alpideEnergies;
    std::vector<double> alpidePositionsX;
    std::vector<double> alpidePositionsY;

    
    
    for (Int_t ihit = 0; ihit < nHitsAL; ihit++)
    {	
	R3BAlpideHitData* hit = dynamic_cast<R3BAlpideHitData*>(fHitItemsAlpide->At(ihit));
        if (!hit)
        	continue;
        alpideEnergies.push_back(hit->GetClusterSize());
        alpidePositionsX.push_back(hit->GetX());
        alpidePositionsY.push_back(hit->GetY());
    }
    

    if (alpideEnergies.size() == 0)
    {
        // R3BLOG("info", "Different number of hits in FOOT and ALPIDE");
        std::cout << "No ALPIDE hits";
    }
    else
    {
	 for (Int_t ihit = 0; ihit < nHitsAL; ihit++)
    	{   
        	R3BAlpideHitData* hit = dynamic_cast<R3BAlpideHitData*>(fHitItemsAlpide->At(ihit));

		auto idet = hit->GetSensorId() - 1;
        	for (int i = 0; i < alpidePositionsX.size(); i++)
  		{	
			for (const auto& vtemp : VMw)
            		{

				if (idet < 6){
			
					fh2_cor[0]->Fill(alpidePositionsX[i], vtemp.X());
                			fh2_cor[1]->Fill(alpidePositionsY[i], vtemp.Y());
				}			
			}
				
			for (const auto& vtemp : VMw)
                        {

					if (idet<12){
						fh2_cor[2]->Fill(alpidePositionsX[i], vtemp.X());
                                		fh2_cor[3]->Fill(alpidePositionsY[i], vtemp.Y());
					}
            		}
    	}    	}
    }



   /*for (size_t ihit = 0; ihit < nHitsFo; ihit++)
    {
        auto hit = dynamic_cast<R3BFootHitData*>(fHitItemsFoot->At(ihit));
        auto idet = hit->GetDetId() - 1;
        auto pos = hit->GetPos();
        if (idet < 0)
            continue;

        if (idet == 0 || idet == 2) // Foot detectors in X
            for (const auto& vtemp : VMw)
            {
                auto index = idet == 0 ? 0 : 1;
                if (abs(vtemp.X() - pos) < fMinDist)
                    fh2_cor[index]->Fill(pos, vtemp.X());
            }
        else if (idet == 1 || idet == 3) // Foot detectors in Y
            for (const auto& vtemp : VMw)
            {
                auto index = idet == 1 ? 2 : 3;
                if (abs(vtemp.Y() - pos) < fMinDist)
                    fh2_cor[index]->Fill(pos, vtemp.Y());
            }

        if (idet == 1) // Foot detector in Y closer to MW
            for (const auto& vtemp : VMw)
            {
                fh2_cor[fNbHist - 2]->Fill(vtemp.X(), pos);
            }

        if (idet == 0) // Foot detector in X closer to MW
            for (const auto& vtemp : VMw)
            {
                fh2_cor[fNbHist - 1]->Fill(pos, vtemp.Y());
            }
    }*/
    fNEvents++;
}

void R3BMwpcvsAlpideOnlineSpectra::FinishEvent()
{
    if (fHitItemsMw)
    {
        fHitItemsMw->Clear();
    }
    if (fHitItemsAlpide)
    {
        fHitItemsAlpide->Clear();
    }
}

void R3BMwpcvsAlpideOnlineSpectra::FinishTask()
{
    // Write canvas for Hit data
    if (fHitItemsMw && fHitItemsAlpide)
    {
        for (const auto& hist : fh2_cor)
        {
            hist->Write();
        }
    }
}

ClassImp(R3BMwpcvsAlpideOnlineSpectra)
