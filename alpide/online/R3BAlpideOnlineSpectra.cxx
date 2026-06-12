// ROOT headers
#include <TCanvas.h>
#include <TClonesArray.h>
#include <TFolder.h>
#include <TGaxis.h>
#include <TH1F.h>
#include <TH2F.h>
#include <THttpServer.h>
#include <TLine.h>
#include <TMath.h>
#include <cmath>
#include <vector>

// FAIR headers
#include <FairLogger.h>
#include <FairRootManager.h>
#include <FairRunOnline.h>
#include <FairRuntimeDb.h>

// R3B headers
#include "R3BAlpideCalData.h"
#include "R3BAlpideHitData.h"
#include "R3BAlpideMappedData.h"
#include "R3BAlpideMappingPar.h"
#include "R3BAlpideOnlineSpectra.h"
#include "R3BEventHeader.h"
#include "R3BLogger.h"
#include "R3BShared.h"

namespace
{
Int_t GetAlpide202606Group(Int_t sensorId)
{
    // 202606 geometry:
    //   group 0: Telescope 1, sensors 1--3
    //   group 1: Linear module 1, sensors 4--12
    //   group 2: Linear module 2, sensors 13--21
    //   group 3: Telescope 2, sensors 22--24
    //   group 4: Extra single sensor, sensor 25 = MOS9 chip 0
    if (sensorId >= 1 && sensorId <= 3)
        return 0;
    if (sensorId >= 4 && sensorId <= 12)
        return 1;
    if (sensorId >= 13 && sensorId <= 21)
        return 2;
    if (sensorId >= 22 && sensorId <= 24)
        return 3;
    if (sensorId == 25)
        return 4;

    return -1;
}

const char* GetAlpide202606GroupName(Int_t group)
{
    static const char* names[5] = { "telescope1", "linear_module1", "linear_module2", "telescope2", "extra_sensor" };

    if (group < 0 || group >= 5)
        return "unknown";

    return names[group];
}

const char* GetAlpide202606GroupTitle(Int_t group)
{
    static const char* titles[5] = { "Telescope 1, sensors 1--3",
                                     "Linear module 1, sensors 4--12",
                                     "Linear module 2, sensors 13--21",
                                     "Telescope 2, sensors 22--24",
                                     "Extra single sensor, sensor 25" };

    if (group < 0 || group >= 5)
        return "Unknown group";

    return titles[group];
}
}

// R3BAlpideOnlineSpectra::Default Constructor --------------------------
R3BAlpideOnlineSpectra::R3BAlpideOnlineSpectra()
    : R3BAlpideOnlineSpectra("AlpideOnlineSpectra", 1)
{
}

// R3BAlpideOnlineSpectra::Standard Constructor --------------------------
R3BAlpideOnlineSpectra::R3BAlpideOnlineSpectra(const TString& name, int iVerbose)
    : FairTask(name, iVerbose)
{
}

void R3BAlpideOnlineSpectra::SetParContainers()
{
    // Parameter Container
    FairRuntimeDb* rtdb = FairRuntimeDb::instance();
    R3BLOG_IF(fatal, rtdb == nullptr, "FairRuntimeDb not found");

    fMap_Par = dynamic_cast<R3BAlpideMappingPar*>(rtdb->getContainer("alpideMappingPar"));
    R3BLOG_IF(fatal, fMap_Par == nullptr, "Container alpideMappingPar not found");
}

void R3BAlpideOnlineSpectra::SetParameter()
{
    //--- Parameter Container ---
    if (fMap_Par)
    {
        fNbSensors = fMap_Par->GetNbSensors();
        R3BLOG(info, "Nb of sensors: " << fNbSensors);
        R3BLOG(info, "Geometry version: " << fMap_Par->GetGeoVersion());
    }
}

InitStatus R3BAlpideOnlineSpectra::Init()
{
    R3BLOG(info, "");
    FairRootManager* mgr = FairRootManager::Instance();
    R3BLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    header = dynamic_cast<R3BEventHeader*>(mgr->GetObject("EventHeader."));
    R3BLOG_IF(error, header == nullptr, "EventHeader. not found");
    R3BLOG_IF(info, header, "EventHeader. found");

    FairRunOnline* run = FairRunOnline::Instance();
    run->GetHttpServer()->Register("", this);

    fMappedItems = dynamic_cast<TClonesArray*>(mgr->GetObject("AlpideMappedData"));
    R3BLOG_IF(fatal, fMappedItems == nullptr, "AlpideMappedData not found");

    fCalItems = dynamic_cast<TClonesArray*>(mgr->GetObject("AlpideCalData"));
    R3BLOG_IF(warn, fCalItems == nullptr, "AlpideCalData not found");

    fHitItems = dynamic_cast<TClonesArray*>(mgr->GetObject("AlpideHitData"));
    R3BLOG_IF(warn, fHitItems == nullptr, "AlpideHitData not found");

    // MAIN FOLDER-ALPIDE
    auto* mainfol = new TFolder("ALPIDE", "Alpide info");
    auto* mapfol = new TFolder("Map", "Map Alpide info");
    auto* calfol = new TFolder("Cal", "Cal Alpide info");
    auto* hitfol = new TFolder("Hit", "Hit Alpide info");

    SetParameter();

    const Int_t geoVersion = fMap_Par ? fMap_Par->GetGeoVersion() : 0;
    const Bool_t is202606 = (geoVersion == 202606);

    if (is202606 && fNbSensors != 25)
    {
        R3BLOG(warn, "202606 online spectra expects 25 sensors, but mapping parameter gives " << fNbSensors);
    }

    // -------------------------------------------------------------------------
    // Mapped spectra: one row/col map per sensor.
    // -------------------------------------------------------------------------
    auto* cMap = new TCanvas("Sensor_mapping", "Row vs Col per sensor", 10, 10, 1200, 900);
    const Int_t nMapRows = (fNbSensors + 2) / 3; // round up fNbSensors / 3
    cMap->Divide(3, nMapRows);

    for (int s = 0; s < fNbSensors; s++)
    {
        std::string hist_name = "fh2_col_vs_row_sensor_" + std::to_string(s + 1);
        std::string hist_title = "Col vs Row for sensor " + std::to_string(s + 1);
        fh2_ColVsRow.push_back(
            R3B::root_owned<TH2F>(hist_name.c_str(), hist_title.c_str(), 1024, 1, 1025, 512, 1, 513));
        fh2_ColVsRow[s]->GetXaxis()->SetTitle("Col");
        fh2_ColVsRow[s]->GetYaxis()->SetTitle("Row");
        fh2_ColVsRow[s]->GetYaxis()->SetTitleOffset(1.1);
        fh2_ColVsRow[s]->GetXaxis()->CenterTitle(true);
        fh2_ColVsRow[s]->GetYaxis()->CenterTitle(true);
        cMap->cd(s + 1);
        fh2_ColVsRow[s]->Draw("colz");
    }
    mapfol->Add(cMap);
    mainfol->Add(mapfol);

    // -------------------------------------------------------------------------
    // Cal spectra.
    // -------------------------------------------------------------------------
    if (fCalItems)
    {
        std::vector<TCanvas*> cCal;
        const Int_t sensorsPerCalCanvas = 6;
        const Int_t nbc = (fNbSensors + sensorsPerCalCanvas - 1) / sensorsPerCalCanvas;

        for (int c = 0; c < nbc; c++)
        {
            std::string name = "Sensor_after_masking_group_" + std::to_string(c + 1);
            cCal.push_back(new TCanvas(name.c_str(), "Row vs Col and multiplicity per sensor", 10, 10, 900, 900));
            cCal[c]->Divide(2, sensorsPerCalCanvas);
        }

        for (int s = 0; s < fNbSensors; s++)
        {
            int canvas_index = s / sensorsPerCalCanvas;
            int pad_index = 2 * (s % sensorsPerCalCanvas) + 1;

            std::string hist_name = "fh2_col_vs_row_cal_sensor_" + std::to_string(s + 1);
            std::string hist_title = "Col vs Row for sensor " + std::to_string(s + 1);
            fh2_ColVsRowCal.push_back(
                R3B::root_owned<TH2F>(hist_name.c_str(), hist_title.c_str(), 1024, 1, 1025, 512, 1, 513));
            fh2_ColVsRowCal[s]->GetXaxis()->SetTitle("Col");
            fh2_ColVsRowCal[s]->GetYaxis()->SetTitle("Row");
            fh2_ColVsRowCal[s]->GetYaxis()->SetTitleOffset(1.1);
            fh2_ColVsRowCal[s]->GetXaxis()->CenterTitle(true);
            fh2_ColVsRowCal[s]->GetYaxis()->CenterTitle(true);
            cCal[canvas_index]->cd(pad_index);
            fh2_ColVsRowCal[s]->Draw("colz");

            std::string hist_name2 = "fh1_mulcal_sensor_" + std::to_string(s + 1);
            std::string hist_title2 = "Cal_mult for sensor " + std::to_string(s + 1);
            fh1_Calmult.push_back(R3B::root_owned<TH1F>(hist_name2.c_str(), hist_title2.c_str(), 100, 0, 100));
            fh1_Calmult[s]->GetXaxis()->SetTitle("Pixel multiplicity");
            fh1_Calmult[s]->GetYaxis()->SetTitle("Counts");
            fh1_Calmult[s]->GetYaxis()->SetTitleOffset(1.1);
            fh1_Calmult[s]->GetXaxis()->CenterTitle(true);
            fh1_Calmult[s]->GetYaxis()->CenterTitle(true);
            fh1_Calmult[s]->SetLineColor(1);
            fh1_Calmult[s]->SetFillColor(31);
            pad_index++;
            cCal[canvas_index]->cd(pad_index);
            fh1_Calmult[s]->Draw();
        }

        for (const auto& c : cCal)
        {
            calfol->Add(c);
        }
        mainfol->Add(calfol);

        fh1_Calmult_total =
            R3B::root_owned<TH1F>("fh1_mulcal_sensor_total", "Cal_mult for all sensors", 70, -0.5, 69.5);
        fh1_Calmult_total->GetXaxis()->SetTitle("Pixel multiplicity");
        fh1_Calmult_total->GetYaxis()->SetTitle("Counts");
        fh1_Calmult_total->GetYaxis()->SetTitleOffset(1.1);
        fh1_Calmult_total->GetXaxis()->CenterTitle(true);
        fh1_Calmult_total->GetYaxis()->CenterTitle(true);
        fh1_Calmult_total->SetLineColor(1);
        fh1_Calmult_total->SetFillColor(31);

        cCalPixelSize = new TCanvas("SensorID_PixelSize", "Pixel multiplicity per sensor", 10, 10, 900, 600);
        fh2_sensor_pixelsize = R3B::root_owned<TH2F>("fh2_sensor_pixelsize",
                                                     "Pixel multiplicity per sensor",
                                                     fNbSensors + 2,
                                                     -0.5,
                                                     fNbSensors + 1.5,
                                                     70,
                                                     -0.5,
                                                     69.5);
        fh2_sensor_pixelsize->GetXaxis()->SetTitle("SensorID");
        fh2_sensor_pixelsize->GetYaxis()->SetTitle("Pixel multiplicity");
        fh2_sensor_pixelsize->GetYaxis()->SetTitleOffset(1.1);
        fh2_sensor_pixelsize->GetXaxis()->CenterTitle(true);
        fh2_sensor_pixelsize->GetYaxis()->CenterTitle(true);
        gPad->SetLogz();
        fh2_sensor_pixelsize->Draw("colz");
        fh2_sensor_pixelsize->SetStats(0);

        if (is202606)
        {
            // Draw boundaries after sensor groups:
            // 1--3 | 4--12 | 13--21 | 22--24 | 25
            const std::vector<Double_t> boundaries = { 3.5, 12.5, 21.5, 24.5 };
            for (auto boundary : boundaries)
            {
                auto* l = new TLine(boundary, 0, boundary, 69);
                l->Draw("same");
                l->SetLineStyle(7);
                l->SetLineWidth(3);
                l->SetLineColor(2);
            }
        }
        else
        {
            for (Int_t i_mosaic = 1; i_mosaic <= nbc; i_mosaic++)
            {
                auto* l = new TLine(sensorsPerCalCanvas * i_mosaic + 0.5, 0, sensorsPerCalCanvas * i_mosaic + 0.5, 69);
                l->Draw("same");
                l->SetLineStyle(7);
                l->SetLineWidth(3);
                l->SetLineColor(2);
            }
        }

        mainfol->Add(fh1_Calmult_total);
        mainfol->Add(cCalPixelSize);
    }

    // -------------------------------------------------------------------------
    // Hit spectra.
    // -------------------------------------------------------------------------
    if (fHitItems)
    {
        char Name1[255];
        char Name2[255];
        fh1_Clustermult.resize(fNbSensors);
        fh1_Clustersize.resize(fNbSensors);
        fh2_PosHit.resize(fNbSensors);

        for (int s = 0; s < fNbSensors; s++)
        {
            sprintf(Name1, "Cluster_size_sensor_%d", s + 1);
            auto* cHit = new TCanvas(Name1, "hit info", 10, 10, 800, 400);
            cHit->Divide(2, 1);

            sprintf(Name1, "fh2_pos_hit_sensor_%d", s + 1);
            sprintf(Name2, "Hit-position for sensor: %d", s + 1);
            fh2_PosHit[s] = R3B::root_owned<TH2F>(Name1, Name2, 200, -20., 40., 120, -20., 20.);
            fh2_PosHit[s]->GetXaxis()->SetTitle("Local X / Posl [mm]");
            fh2_PosHit[s]->GetYaxis()->SetTitle("Local Y / Post [mm]");
            fh2_PosHit[s]->GetYaxis()->SetTitleOffset(1.1);
            fh2_PosHit[s]->GetXaxis()->CenterTitle(true);
            fh2_PosHit[s]->GetYaxis()->CenterTitle(true);
            cHit->cd(1);
            fh2_PosHit[s]->Draw("colz");

            sprintf(Name1, "fh1_cluster_size_sensor_%d", s + 1);
            sprintf(Name2, "Cluster_size for sensor: %d", s + 1);
            fh1_Clustersize[s] = R3B::root_owned<TH1F>(Name1, Name2, 160, 0, 160);
            fh1_Clustersize[s]->GetXaxis()->SetTitle("Cluster size [pixels]");
            fh1_Clustersize[s]->GetYaxis()->SetTitle("Counts");
            fh1_Clustersize[s]->GetYaxis()->SetTitleOffset(1.1);
            fh1_Clustersize[s]->GetXaxis()->CenterTitle(true);
            fh1_Clustersize[s]->GetYaxis()->CenterTitle(true);
            fh1_Clustersize[s]->SetLineColor(1);
            fh1_Clustersize[s]->SetFillColor(31);
            cHit->cd(2);
            fh1_Clustersize[s]->Draw();
            hitfol->Add(cHit);

            sprintf(Name1, "Cluster_multiplicity_sensor_%d", s + 1);
            auto* cHitm = new TCanvas(Name1, "cluster multiplicity", 10, 10, 500, 500);
            sprintf(Name1, "fh1_cluster_multiplicity_sensor_%d", s + 1);
            sprintf(Name2, "Cluster_multiplicity for sensor: %d", s + 1);
            fh1_Clustermult[s] = R3B::root_owned<TH1F>(Name1, Name2, 60, 0, 60);
            fh1_Clustermult[s]->GetXaxis()->SetTitle("Cluster multiplicity");
            fh1_Clustermult[s]->GetYaxis()->SetTitle("Counts");
            fh1_Clustermult[s]->GetYaxis()->SetTitleOffset(1.1);
            fh1_Clustermult[s]->GetXaxis()->CenterTitle(true);
            fh1_Clustermult[s]->GetYaxis()->CenterTitle(true);
            fh1_Clustermult[s]->SetLineColor(1);
            fh1_Clustermult[s]->SetFillColor(31);
            cHitm->cd();
            fh1_Clustermult[s]->Draw();
            hitfol->Add(cHitm);
        }

        auto* cHitmTot = new TCanvas("Cluster_multiplicity_total", "mult hit info", 10, 10, 500, 500);
        fh1_Clustermult_total =
            R3B::root_owned<TH1F>("Cluster_multiplicity_total", "Total cluster multiplicity", 60, 0, 60);
        fh1_Clustermult_total->GetXaxis()->SetTitle("Cluster multiplicity");
        fh1_Clustermult_total->GetYaxis()->SetTitle("Counts");
        fh1_Clustermult_total->GetYaxis()->SetTitleOffset(1.1);
        fh1_Clustermult_total->GetXaxis()->CenterTitle(true);
        fh1_Clustermult_total->GetYaxis()->CenterTitle(true);
        fh1_Clustermult_total->SetLineColor(1);
        fh1_Clustermult_total->SetFillColor(31);
        cHitmTot->cd();
        fh1_Clustermult_total->Draw();
        hitfol->Add(cHitmTot);

        auto* cSizemTot = new TCanvas("Size_multiplicity_total", "size hit info", 10, 10, 500, 500);
        fh1_Clustersize_total = R3B::root_owned<TH1F>("Size_multiplicity_total", "Total size multiplicity", 160, 0, 160);
        fh1_Clustersize_total->GetXaxis()->SetTitle("Cluster size [pixels]");
        fh1_Clustersize_total->GetYaxis()->SetTitle("Counts");
        fh1_Clustersize_total->GetYaxis()->SetTitleOffset(1.1);
        fh1_Clustersize_total->GetXaxis()->CenterTitle(true);
        fh1_Clustersize_total->GetYaxis()->CenterTitle(true);
        fh1_Clustersize_total->SetLineColor(1);
        fh1_Clustersize_total->SetFillColor(31);
        cSizemTot->cd();
        fh1_Clustersize_total->Draw();
        hitfol->Add(cSizemTot);

        mainfol->Add(hitfol);

        cHit_angcor = new TCanvas("Theta_vs_Phi", "Correlation theta vs phi", 10, 10, 500, 500);
        fh2_theta_phi = R3B::root_owned<TH2F>("fh2_theta_phi", "Correlation theta vs phi", 400, -180, 180, 140, 10, 80);
        fh2_theta_phi->GetXaxis()->SetTitle("Phi [deg]");
        fh2_theta_phi->GetYaxis()->SetTitle("Theta [deg]");
        fh2_theta_phi->GetYaxis()->SetTitleOffset(1.1);
        fh2_theta_phi->GetXaxis()->CenterTitle(true);
        fh2_theta_phi->GetYaxis()->CenterTitle(true);
        gPad->SetLogz();
        fh2_theta_phi->Draw("colz");
        fh2_theta_phi->SetStats(0);

        auto* cHit_xy = new TCanvas("Y_vs_X", "Correlation Y vs X in mm", 10, 10, 1200, 800);

	auto* cHit_yy = new TCanvas("Y_vs_Y", "Correlation Y vs Y in mm", 10, 10, 1200, 800);

	auto* cHit_xx = new TCanvas("X_vs_X", "Correlation X vs X in mm", 10, 10, 1200, 800);

        if (is202606)
        {
            cHit_xy->Divide(3, 2);

            for (Int_t group = 0; group < 5; group++)
            {
                cHit_xy->cd(group + 1);

                std::string histName = std::string("fh2_y_x_") + GetAlpide202606GroupName(group);
                std::string histTitle = std::string("Hit Y vs X, ") + GetAlpide202606GroupTitle(group);
		if (group != 1 && group!= 2){
                	fh2_y_x.push_back(
                    	R3B::root_owned<TH2F>(histName.c_str(), histTitle.c_str(), 400, -40., 40., 240, -20., 20.));
		
                	fh2_y_x[group]->GetXaxis()->SetTitle("X [mm]");
                	fh2_y_x[group]->GetYaxis()->SetTitle("Y [mm]");
                	fh2_y_x[group]->GetYaxis()->SetTitleOffset(1.1);
                	fh2_y_x[group]->GetXaxis()->CenterTitle(true);
                	fh2_y_x[group]->GetYaxis()->CenterTitle(true);
                	gPad->SetLogz();
                	fh2_y_x[group]->Draw("colz");
            	}
		else {

			fh2_y_x.push_back(
                        R3B::root_owned<TH2F>(histName.c_str(), histTitle.c_str(), 400, -270., 270., 240, -20., 20.));
                
                        fh2_y_x[group]->GetXaxis()->SetTitle("X [mm]");
                        fh2_y_x[group]->GetYaxis()->SetTitle("Y [mm]");
                        fh2_y_x[group]->GetYaxis()->SetTitleOffset(1.1);
                        fh2_y_x[group]->GetXaxis()->CenterTitle(true);
                        fh2_y_x[group]->GetYaxis()->CenterTitle(true);
                        gPad->SetLogz();
                        fh2_y_x[group]->Draw("colz");
		}

	}

            mainfol->Add(cHit_xy);

	    cHit_yy ->Divide(3,2);
	    
	    for (Int_t group = 0; group < 5; group++)
            {
                cHit_yy->cd(group + 1);

                std::string histName = std::string("fh2_yy_") + GetAlpide202606GroupName(group);
                std::string histTitle = std::string("Hit Y vs Y, ") + GetAlpide202606GroupTitle(group);

		
                fh2_yy.push_back(
                    R3B::root_owned<TH2F>(histName.c_str(), histTitle.c_str(), 400, -40., 40., 240, -20., 20.));

                fh2_yy[group]->GetXaxis()->SetTitle("Y [mm]");
                fh2_yy[group]->GetYaxis()->SetTitle("Y [mm]");
                fh2_yy[group]->GetYaxis()->SetTitleOffset(1.1);
                fh2_yy[group]->GetXaxis()->CenterTitle(true);
                fh2_yy[group]->GetYaxis()->CenterTitle(true);
                gPad->SetLogz();
                fh2_yy[group]->Draw("colz");
            }

            mainfol->Add(cHit_yy);


	   cHit_xx ->Divide(3,2);
            for (Int_t group = 0; group < 5; group++)
            {
                cHit_xx->cd(group + 1);

                std::string histName = std::string("fh2_xx_") + GetAlpide202606GroupName(group);
                std::string histTitle = std::string("Hit X vs X, ") + GetAlpide202606GroupTitle(group);

                fh2_xx.push_back(
                    R3B::root_owned<TH2F>(histName.c_str(), histTitle.c_str(), 400, -40., 40., 240, -20., 20.));

                fh2_xx[group]->GetXaxis()->SetTitle("X [mm]");
                fh2_xx[group]->GetYaxis()->SetTitle("X [mm]");
                fh2_xx[group]->GetYaxis()->SetTitleOffset(1.1);
                fh2_xx[group]->GetXaxis()->CenterTitle(true);
                fh2_xx[group]->GetYaxis()->CenterTitle(true);
                gPad->SetLogz();
                fh2_xx[group]->Draw("colz");
            }

            mainfol->Add(cHit_xx);


            auto* cHit_xy_cor_202606 =
                new TCanvas("Y_vs_X_202606_summary", "202606 group hit maps", 10, 10, 1200, 800);
            cHit_xy_cor_202606->Divide(3, 2);
            mainfol->Add(cHit_xy_cor_202606);
        }
        else if (fMap_Par->GetGeoVersion() == 202505)
        {
            fh2_y_x.push_back(R3B::root_owned<TH2F>("fh2_y_x", "Correlation Y vs X in mm", 400, -50, 50, 380, -70, 70));
            fh2_y_x[0]->GetXaxis()->SetTitle("Wix <--   X [mm]   --> Messel");
            fh2_y_x[0]->GetYaxis()->SetTitle("Y [mm]");
            fh2_y_x[0]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x[0]->GetXaxis()->CenterTitle(true);
            fh2_y_x[0]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x[0]->Draw("colz");
            mainfol->Add(cHit_xy);
        }
        else
        {
            cHit_xy->Divide(1, 2);
            cHit_xy->cd(1);
            fh2_y_x.push_back(R3B::root_owned<TH2F>(
                "fh2_y_x_flex1", "Correlation Y vs X in mm for flex-1", 500, -50, 50, 200, -20, 20));
            fh2_y_x[0]->GetXaxis()->SetTitle("Wix <--   X [mm]   --> Messel");
            fh2_y_x[0]->GetYaxis()->SetTitle("Y [mm]");
            fh2_y_x[0]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x[0]->GetXaxis()->CenterTitle(true);
            fh2_y_x[0]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x[0]->Draw("colz");

            cHit_xy->cd(2);
            fh2_y_x.push_back(R3B::root_owned<TH2F>(
                "fh2_y_x_flex2", "Correlation Y vs X in mm for flex-2", 500, -50, 50, 200, -20, 20));
            fh2_y_x[1]->GetXaxis()->SetTitle("Wix <--   X [mm]   --> Messel");
            fh2_y_x[1]->GetYaxis()->SetTitle("Y [mm]");
            fh2_y_x[1]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x[1]->GetXaxis()->CenterTitle(true);
            fh2_y_x[1]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x[1]->Draw("colz");
            mainfol->Add(cHit_xy);

            auto* cHit_xy_cor =
                new TCanvas("Y_vs_X_flex_cor", "Position correlations between flex-PCBs", 10, 10, 500, 500);
            cHit_xy_cor->Divide(2, 2);
            cHit_xy_cor->cd(1);
            fh2_y_x_cor_det.push_back(
                R3B::root_owned<TH2F>("fh2_x_x_flexes", "Correlation X2 vs X1 in mm", 500, -50, 50, 500, -50, 50));
            fh2_y_x_cor_det[0]->GetXaxis()->SetTitle("Wix <--   X1 [mm]   --> Messel");
            fh2_y_x_cor_det[0]->GetYaxis()->SetTitle("Wix <--   X2 [mm]   --> Messel");
            fh2_y_x_cor_det[0]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x_cor_det[0]->GetXaxis()->CenterTitle(true);
            fh2_y_x_cor_det[0]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x_cor_det[0]->Draw("colz");

            cHit_xy_cor->cd(2);
            fh2_y_x_cor_det.push_back(
                R3B::root_owned<TH2F>("fh2_y_y_flexes", "Correlation Y2 vs Y1 in mm", 200, -20, 20, 200, -20, 20));
            fh2_y_x_cor_det[1]->GetXaxis()->SetTitle("Y1 [mm]");
            fh2_y_x_cor_det[1]->GetYaxis()->SetTitle("Y2 [mm]");
            fh2_y_x_cor_det[1]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x_cor_det[1]->GetXaxis()->CenterTitle(true);
            fh2_y_x_cor_det[1]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x_cor_det[1]->Draw("colz");

            cHit_xy_cor->cd(3);
            fh2_y_x_cor_det.push_back(
                R3B::root_owned<TH2F>("fh2_y2_x1_flexes", "Correlation Y2 vs X1 in mm", 500, -50, 50, 200, -20, 20));
            fh2_y_x_cor_det[2]->GetXaxis()->SetTitle("Wix <--   X1 [mm]   --> Messel");
            fh2_y_x_cor_det[2]->GetYaxis()->SetTitle("Y2 [mm]");
            fh2_y_x_cor_det[2]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x_cor_det[2]->GetXaxis()->CenterTitle(true);
            fh2_y_x_cor_det[2]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x_cor_det[2]->Draw("colz");

            cHit_xy_cor->cd(4);
            fh2_y_x_cor_det.push_back(
                R3B::root_owned<TH2F>("fh2_y1_x2_flexes", "Correlation Y1 vs X2 in mm", 500, -50, 50, 200, -20, 20));
            fh2_y_x_cor_det[3]->GetXaxis()->SetTitle("Wix <--   X2 [mm]   --> Messel");
            fh2_y_x_cor_det[3]->GetYaxis()->SetTitle("Y1 [mm]");
            fh2_y_x_cor_det[3]->GetYaxis()->SetTitleOffset(1.1);
            fh2_y_x_cor_det[3]->GetXaxis()->CenterTitle(true);
            fh2_y_x_cor_det[3]->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_y_x_cor_det[3]->Draw("colz");
            mainfol->Add(cHit_xy_cor);

            auto* cHit_cluster =
                new TCanvas("Cluster_correlations", "Cluster size correlations between flex-PCBs", 10, 10, 500, 500);
            fh2_max_clusters =
                R3B::root_owned<TH2F>("fh2_max_clusters", "Correlation max. clusters", 70, 0, 70, 70, 0, 70);
            fh2_max_clusters->GetXaxis()->SetTitle("Max. cluster flex-1");
            fh2_max_clusters->GetYaxis()->SetTitle("Max. cluster flex-2");
            fh2_max_clusters->GetYaxis()->SetTitleOffset(1.1);
            fh2_max_clusters->GetXaxis()->CenterTitle(true);
            fh2_max_clusters->GetYaxis()->CenterTitle(true);
            gPad->SetLogz();
            fh2_max_clusters->Draw("colz");
            fh2_max_clusters->SetStats(0);
            mainfol->Add(cHit_cluster);
        }
    }

    run->AddObject(mainfol);

    // Register command to reset histograms
    run->GetHttpServer()->RegisterCommand("Reset_ALPIDE_HIST", Form("/Objects/%s/->Reset_Histo()", GetName()));

    return kSUCCESS;
}

// -----   Public method ReInit   ----------------------------------------------
InitStatus R3BAlpideOnlineSpectra::ReInit()
{
    SetParContainers();
    SetParameter();
    return kSUCCESS;
}

void R3BAlpideOnlineSpectra::Reset_Histo()
{
    R3BLOG(info, "");

    if (fMappedItems)
    {
        for (const auto& hist : fh2_ColVsRow)
        {
            if (hist)
                hist->Reset();
        }
    }

    if (fCalItems)
    {
        for (const auto& hist : fh2_ColVsRowCal)
        {
            if (hist)
                hist->Reset();
        }
        for (const auto& hist : fh1_Calmult)
        {
            if (hist)
                hist->Reset();
        }
        if (fh1_Calmult_total)
            fh1_Calmult_total->Reset();
        if (fh2_sensor_pixelsize)
            fh2_sensor_pixelsize->Reset();
    }

    if (fHitItems)
    {
        for (const auto& hist : fh1_Clustermult)
        {
            if (hist)
                hist->Reset();
        }
        for (const auto& hist : fh1_Clustersize)
        {
            if (hist)
                hist->Reset();
        }
        for (const auto& hist : fh2_PosHit)
        {
            if (hist)
                hist->Reset();
        }
        for (const auto& hist : fh2_y_x)
        {
            if (hist)
                hist->Reset();
        }

	for (const auto& hist : fh2_yy)
        {
            if (hist)
                hist->Reset();
        }

	for (const auto& hist : fh2_xx)
        {
            if (hist)
                hist->Reset();
        }


        for (const auto& hist : fh2_y_x_cor_det)
        {
            if (hist)
                hist->Reset();
        }

        if (fh2_theta_phi)
            fh2_theta_phi->Reset();
        if (fh2_max_clusters)
            fh2_max_clusters->Reset();
        if (fh1_Clustermult_total)
            fh1_Clustermult_total->Reset();
        if (fh1_Clustersize_total)
            fh1_Clustersize_total->Reset();
    }

    return;
}

void R3BAlpideOnlineSpectra::Exec(Option_t* /*option*/)
{
    // Check for requested trigger.
    if ((fTrigger >= 0) && (header != nullptr) && (header->GetTrigger() != fTrigger))
        return;

    if (fTpat1 >= 0 && fTpat2 >= 0 && (header))
    {
        // fTpat = 1-16; fTpat_bit = 0-15
        Int_t fTpat_bit1 = fTpat1 - 1;
        Int_t fTpat_bit2 = fTpat2 - 1;
        Int_t tpatbin = 0;
        for (int i = 0; i < 16; i++)
        {
            tpatbin = (header->GetTpat() & (1 << i));
            if (tpatbin != 0 && (i < fTpat_bit1 || i > fTpat_bit2))
            {
                return;
            }
        }
    }

    const Int_t geoVersion = fMap_Par ? fMap_Par->GetGeoVersion() : 0;
    const Bool_t is202606 = (geoVersion == 202606);

    // Fill mapped data
    if (fMappedItems && fMappedItems->GetEntriesFast() > 0)
    {
        auto nHits = fMappedItems->GetEntriesFast();
        for (size_t ihit = 0; ihit < nHits; ihit++)
        {
            auto hit = dynamic_cast<R3BAlpideMappedData*>(fMappedItems->At(ihit));
            if (!hit)
                continue;

            const Int_t sensorId = hit->GetSensorId();
            if (sensorId < 1 || sensorId > fNbSensors)
            {
                R3BLOG(error, "Mapped hit with invalid sensor ID: " << sensorId);
                continue;
            }

            fh2_ColVsRow[sensorId - 1]->Fill(hit->GetCol(), hit->GetRow());
        }
    }

    // Fill cal data
    if (fCalItems)
    {
        if (fCalItems->GetEntriesFast() > 0)
        {
            std::vector<int> mult(fNbSensors, 0);
            auto nHits = fCalItems->GetEntriesFast();
            for (size_t ihit = 0; ihit < nHits; ihit++)
            {
                auto hit = dynamic_cast<R3BAlpideCalData*>(fCalItems->At(ihit));
                if (!hit)
                    continue;

                const Int_t sensorId = hit->GetSensorId();
                if (sensorId < 1 || sensorId > fNbSensors)
                {
                    R3BLOG(error, "Cal hit with invalid sensor ID: " << sensorId);
                    continue;
                }

                const Int_t senid = sensorId - 1;
                fh2_ColVsRowCal[senid]->Fill(hit->GetCol(), hit->GetRow());
                mult[senid]++;
            }

            for (size_t s = 0; s < static_cast<size_t>(fNbSensors); s++)
            {
                if (mult[s] > 0)
                {
                    fh1_Calmult[s]->Fill(mult[s]);
                    fh1_Calmult_total->Fill(mult[s]);
                    fh2_sensor_pixelsize->Fill(s + 0.5, mult[s]);
                }
            }
        }
    }

    // Fill hit data
    if (fHitItems && fHitItems->GetEntriesFast() > 0)
    {
        std::vector<int> mult(fNbSensors, 0);
        auto nHits = fHitItems->GetEntriesFast();

        std::vector<double> x_max(9, NAN);
        std::vector<double> y_max(9, NAN);
	
        std::vector<int> cls_size(9, 0);

        if (fh1_Clustermult_total)
            fh1_Clustermult_total->Fill(nHits);

        for (size_t ihit = 0; ihit < nHits; ihit++)
        {
            auto hit = dynamic_cast<R3BAlpideHitData*>(fHitItems->At(ihit));
            if (!hit)
                continue;

            const Int_t sensorId = hit->GetSensorId();
            if (sensorId < 1 || sensorId > fNbSensors)
            {
                R3BLOG(error, "Hit with invalid sensor ID: " << sensorId);
                continue;
            }

            const Int_t senid = sensorId - 1;
            fh1_Clustersize[senid]->Fill(hit->GetClusterSize());
            fh2_PosHit[senid]->Fill(hit->GetPosl(), hit->GetPost());
            fh1_Clustersize_total->Fill(hit->GetClusterSize());

            if (is202606)
            {
                const Int_t group = GetAlpide202606Group(sensorId);
                if (group >= 0 && group < static_cast<Int_t>(fh2_y_x.size()))
                {
                    fh2_y_x[group]->Fill(hit->GetX(), hit->GetY());
		    
                }
	        if (senid == 0){

			if (hit->GetClusterSize() > cls_size[0])
			{
				cls_size[0] = hit->GetClusterSize();
                        	x_max[0] = hit->GetX();
                        	y_max[0] = hit->GetY();
				//std::cout << "y" <<y_max[0] << std::endl;

			}

		}

		else if (senid == 1){

			if (hit->GetClusterSize() > cls_size[1])
                        {
                                cls_size[1] = hit->GetClusterSize();
                                x_max[1] = hit->GetX();
                                y_max[1] = hit->GetY();

                        }
		}
		else if (senid == 2){

                        if (hit->GetClusterSize() > cls_size[2])
                        {
                                cls_size[2] = hit->GetClusterSize();
                                x_max[2] = hit->GetX();
                                y_max[2] = hit->GetY();

                        }
                }

		else if (senid < 12){

                        if (hit->GetClusterSize() > cls_size[3])
                        {
                                cls_size[3] = hit->GetClusterSize();
                                x_max[3] = hit->GetX();
                                y_max[3] = hit->GetY();

                        }
                }
		else if (senid < 21){

                        if (hit->GetClusterSize() > cls_size[4])
                        {
                                cls_size[4] = hit->GetClusterSize();
                                x_max[4] = hit->GetX();
                                y_max[4] = hit->GetY();

                        }
                }

		else if (senid == 21){

                        if (hit->GetClusterSize() > cls_size[5])
                        {
                                cls_size[5] = hit->GetClusterSize();
                                x_max[5] = hit->GetX();
                                y_max[5] = hit->GetY();

                        }
                }
		else if (senid == 22){

                        if (hit->GetClusterSize() > cls_size[6])
                        {
                                cls_size[6] = hit->GetClusterSize();
                                x_max[6] = hit->GetX();
                                y_max[6] = hit->GetY();

                        }
                }

		else if (senid ==23){

                        if (hit->GetClusterSize() > cls_size[7])
                        {
                                cls_size[7] = hit->GetClusterSize();
                                x_max[7] = hit->GetX();
                                y_max[7] = hit->GetY();

                        }
                }

		else if (senid == 24){

                        if (hit->GetClusterSize() > cls_size[8])
                        {
                                cls_size[8] = hit->GetClusterSize();
                                x_max[8] = hit->GetX();
                                y_max[8] = hit->GetY();

                        }
                }

		else
                {
                    R3BLOG(error, "202606 hit with unmapped sensor group: sensor " << sensorId);
                }
            }
            else if (fMap_Par->GetGeoVersion() == 202505)
            {
                fh2_theta_phi->Fill(hit->GetPhi() * TMath::RadToDeg(), hit->GetTheta() * TMath::RadToDeg());
                fh2_y_x[0]->Fill(hit->GetX(), hit->GetY());
            }
            else
            {
                if (senid < 6)
                {
                    fh2_y_x[0]->Fill(hit->GetX(), hit->GetY());
                    if (hit->GetClusterSize() > cls_size[0])
                    {
                        cls_size[0] = hit->GetClusterSize();
                        x_max[0] = hit->GetX();
                        y_max[0] = hit->GetY();
                    }
                }
                else
                {
                    fh2_y_x[1]->Fill(hit->GetX(), hit->GetY());
                    if (hit->GetClusterSize() > cls_size[1])
                    {
                        cls_size[1] = hit->GetClusterSize();
                        x_max[1] = hit->GetX();
                        y_max[1] = hit->GetY();
                    }
                }
            }

            mult[senid]++;
        }

        for (size_t s = 0; s < static_cast<size_t>(fNbSensors); s++)
        {
            if (mult[s] > 0)
                fh1_Clustermult[s]->Fill(mult[s]);
        }

        if (!is202606 && fMap_Par->GetGeoVersion() == 202506)
        {
            if (std::isfinite(x_max[0]) && std::isfinite(x_max[1])){
		//std::cout<<"lalala"<<std::endl;
                fh2_y_x_cor_det[0]->Fill(x_max[0], x_max[1]);
	    }
            if (std::isfinite(y_max[0]) && std::isfinite(y_max[1]))
                fh2_y_x_cor_det[1]->Fill(y_max[0], y_max[1]);

            if (std::isfinite(x_max[0]) && std::isfinite(y_max[1]))
                fh2_y_x_cor_det[2]->Fill(x_max[0], y_max[1]);

            if (std::isfinite(x_max[1]) && std::isfinite(y_max[0]))
                fh2_y_x_cor_det[3]->Fill(x_max[1], y_max[0]);

            if (cls_size[0] > 0 && cls_size[1] > 0 && fh2_max_clusters)
                fh2_max_clusters->Fill(cls_size[0], cls_size[1]);
        }
	
	if (is202606)
	{

		if (std::isfinite(x_max[0]) && std::isfinite(x_max[1]))
			fh2_xx[0]->Fill(x_max[0],x_max[1]);
		if (std::isfinite(x_max[0]) && std::isfinite(x_max[2]))
                	fh2_xx[0]->Fill(x_max[0],x_max[2]);

		if(std::isfinite(y_max[0]) && std::isfinite(y_max[1])) 
			fh2_yy[0]->Fill(y_max[0],y_max[1]);

		if(std::isfinite(y_max[0]) && std::isfinite(y_max[2])) 
                        fh2_yy[0]->Fill(y_max[0],y_max[2]);

		if(std::isfinite(x_max[3]) && std::isfinite(x_max[4])) 
                        fh2_xx[1]->Fill(x_max[3],x_max[4]);

		if(std::isfinite(y_max[3]) && std::isfinite(y_max[4])) 
                        fh2_yy[1]->Fill(y_max[3],y_max[4]);
		for (int i = 5; i < 8; i++){
			for (int j=i+1; j < 8;j++){
				if(std::isfinite(x_max[i]) && std::isfinite(x_max[j])){ 
                        		fh2_xx[3]->Fill(x_max[i],x_max[j]);

				}
				if(std::isfinite(y_max[i]) && std::isfinite(y_max[j])){ 
                                        fh2_yy[3]->Fill(y_max[i],y_max[j]);

                                }

			}
		}

	}
    }

    fNEvents++;
    return;
}

void R3BAlpideOnlineSpectra::FinishEvent()
{
    R3BLOG(debug, "Cleaning data structures");
    if (fMappedItems)
    {
        fMappedItems->Clear();
    }
    if (fCalItems)
    {
        fCalItems->Clear();
    }
    if (fHitItems)
    {
        fHitItems->Clear();
    }
}

void R3BAlpideOnlineSpectra::FinishTask()
{
    for (const auto& hist : fh2_ColVsRow)
    {
        if (hist)
            hist->Write();
    }

    if (fCalItems)
    {
        for (const auto& hist : fh2_ColVsRowCal)
        {
            if (hist)
                hist->Write();
        }
        for (const auto& hist : fh1_Calmult)
        {
            if (hist)
                hist->Write();
        }
        if (fh1_Calmult_total)
            fh1_Calmult_total->Write();
        if (fh2_sensor_pixelsize)
            fh2_sensor_pixelsize->Write();
    }

    if (fHitItems)
    {
        if (fh2_theta_phi)
            fh2_theta_phi->Write();

        if (fh2_max_clusters)
            fh2_max_clusters->Write();

        for (const auto& hist : fh2_y_x)
        {
            if (hist)
                hist->Write();
        }

	for (const auto& hist : fh2_xx)
        {
            if (hist)
                hist->Write();
        }
	for (const auto& hist : fh2_yy)
        {
            if (hist)
                hist->Write();
        }


        for (const auto& hist : fh2_y_x_cor_det)
        {
            if (hist)
                hist->Write();
        }

        if (fh1_Clustermult_total)
            fh1_Clustermult_total->Write();
        if (fh1_Clustersize_total)
            fh1_Clustersize_total->Write();
    }
}

ClassImp(R3BAlpideOnlineSpectra)

