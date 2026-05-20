
#include "TGeoManager.h"
#include "TMath.h"
#include <iomanip>
#include <iostream>

void create_HIT2026(const TString geoTag = "HIT202606")
{

    TGeoRotation* fRefRot = NULL;
    TGeoManager* gGeoMan = NULL;

    // -------   Load media from media file   -----------------------------------
    FairGeoLoader* geoLoad = new FairGeoLoader("TGeo", "FairGeoLoader");
    FairGeoInterface* geoFace = geoLoad->getGeoInterface();
    TString geoPath = gSystem->Getenv("VMCWORKDIR");
    TString medFile = geoPath + "/geometry/media_r3b.geo";
    geoFace->setMediaFile(medFile);
    geoFace->readMedia();
    gGeoMan = gGeoManager;
    // --------------------------------------------------------------------------

    // -------   Geometry file name (output)   ----------------------------------
    TString geoFileName = geoPath + "/geometry/alpide_";
    geoFileName = geoFileName + geoTag + ".geo.root";
    // --------------------------------------------------------------------------

    // -----------------   Get and create the required media    -----------------
    FairGeoMedia* geoMedia = geoFace->getMedia();
    FairGeoBuilder* geoBuild = geoLoad->getGeoBuilder();

    FairGeoMedium* mVac = geoMedia->getMedium("vacuum");
    if (!mVac)
        Fatal("Main", "FairMedium vacuum not found");
    geoBuild->createMedium(mVac);
    TGeoMedium* pMedVac = gGeoMan->GetMedium("vacuum");
    if (!pMedVac)
        Fatal("Main", "Medium vacuum not found");

    FairGeoMedium* mSi = geoMedia->getMedium("silicon");
    if (!mSi)
        Fatal("Main", "FairMedium silicon not found");
    geoBuild->createMedium(mSi);
    TGeoMedium* pMedSi = gGeoMan->GetMedium("silicon");
    if (!pMedSi)
        Fatal("Main", "Medium silicon not found");

    // --------------   Create geometry and top volume  -------------------------
    gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
    gGeoMan->SetName("ALPIDE_Telescope_Staves_geom");

    TGeoVolume* top = new TGeoVolumeAssembly("TOP");
    gGeoMan->SetTopVolume(top);

    // Vacuum mother volume. Large enough to contain the full sensor layout.
    TGeoVolume* pWorld = gGeoMan->MakeBox("AlpideSensorWorld", pMedVac, 20.0, 20.0, 40.0);
    pWorld->SetVisLeaves(kTRUE);
    pWorld->SetLineColor(kGray);

    auto t0 = new TGeoCombiTrans(0., 0., 0., fRefRot);
    top->AddNode(pWorld, 0, t0);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // ALPIDE sensor parameters
    // --------------------------------------------------------------------------

    const Double_t chipX = 3.0;      // cm
    const Double_t chipY = 1.5;      // cm
    const Double_t thAlpide = 0.005; // 50 um = 0.005 cm

    // Layout distances along z.
    const Double_t telescopeSpacingZ = 2.0; // cm, centre-to-centre
    const Double_t vacuumGapZ = 2.0;        // cm, from last telescope chip to first stave centre
    const Double_t staveCopySpacingZ = 1.0; // cm, between 9-chip stave centres
    const Double_t finalTelescopeGapZ = 2.0; // cm, from second stave to first chip of second telescope

    // In-plane pitch for the 9-chip linear module.
    // The 9 sensors are placed in a straight line along negative x.
    // Sensor 1 is at x = 0, y = 0, aligned with the telescope sensors.
    const Double_t chipPitchX = 3.0004;

    // Start the layout at z = 0 for a clean standalone sensor geometry.
    const Double_t zFirstTelescope0 = 0.0;

    const Double_t zTel1_0 = zFirstTelescope0;
    const Double_t zTel1_1 = zTel1_0 + telescopeSpacingZ;
    const Double_t zTel1_2 = zTel1_1 + telescopeSpacingZ;

    const Double_t zStave1 = zTel1_2 + vacuumGapZ;
    const Double_t zStave2 = zStave1 + staveCopySpacingZ;

    const Double_t zTel2_0 = zStave2 + finalTelescopeGapZ;
    const Double_t zTel2_1 = zTel2_0 + telescopeSpacingZ;
    const Double_t zTel2_2 = zTel2_1 + telescopeSpacingZ;

    // Silicon ALPIDE sensor volume.
    auto Alpide = gGeoManager->MakeBox("Alpide", pMedSi, chipX / 2., chipY / 2., thAlpide / 2.);
    Alpide->SetLineColor(kOrange);
    Alpide->SetVisLeaves(kTRUE);

    TGeoRotation* rotSensor = new TGeoRotation();

    Int_t copyNo = 0;

    auto AddSingleChip = [&](Double_t x, Double_t y, Double_t z) {
        ++copyNo;
        auto matrix = new TGeoCombiTrans("", x, y, z, rotSensor);
        pWorld->AddNode(Alpide, copyNo, matrix);
    };

    auto AddNineChipStave = [&](Double_t x0, Double_t y0, Double_t z0) {
        for (Int_t i = 0; i < 9; i++)
        {
            AddSingleChip(x0 - chipPitchX * i, y0, z0);
        }
    };


    AddSingleChip(0., 0., zTel1_0); // sensor ID 1
    AddSingleChip(0., 0., zTel1_1); // sensor ID 2
    AddSingleChip(0., 0., zTel1_2); // sensor ID 3


    AddNineChipStave(0., 0., zStave1); // sensor IDs 4--12


    AddNineChipStave(0., 0., zStave2); // sensor IDs 13--21


    AddSingleChip(0., 0., zTel2_0); // sensor ID 22
    AddSingleChip(0., 0., zTel2_1); // sensor ID 23
    AddSingleChip(0., 0., zTel2_2); // sensor ID 24

    AddSingleChip(0.,0.,-10);//Micheal 

    std::cout << "\033[36m ALPIDE sensors-only geometry z positions [cm]:\033[0m" << std::endl;
    std::cout << "  Telescope 1: " << zTel1_0 << ", " << zTel1_1 << ", " << zTel1_2 << std::endl;
    std::cout << "  Vacuum gap:  " << vacuumGapZ << " cm" << std::endl;
    std::cout << "  Linear module 1: " << zStave1 << "  sensor 1 at x=0, sensors 2-9 along -x" << std::endl;
    std::cout << "  Linear module 2: " << zStave2 << "  sensor 1 at x=0, sensors 2-9 along -x" << std::endl;
    std::cout << "  Telescope 2: " << zTel2_0 << ", " << zTel2_1 << ", " << zTel2_2 << std::endl;
    std::cout << "  Total ALPIDE chips: " << copyNo << std::endl;

    // ---------------   Finish   -----------------------------------------------
    gGeoMan->CloseGeometry();
    gGeoMan->CheckOverlaps(0.001);
    gGeoMan->PrintOverlaps();
    gGeoMan->Test();

    TFile* geoFile = new TFile(geoFileName, "RECREATE");
    top->Write();
    geoFile->Close();

    std::cout << "\033[34m Creating geometry:\033[0m "
              << "\033[33m" << geoFileName << " \033[0m" << std::endl;
    std::cout << "Macro finished successfully." << std::endl;
}

