/******************************************************************************
 *   Copyright (C) 2022 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2022-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include <TStopwatch.h>
#include <TString.h>
#include <TSystem.h>
#include <memory>

void testAlpideSimulation(int nbevents = 10000)
{
    // Timer
    TStopwatch timer;
    timer.Start();

    // Logging
    auto logger = FairLogger::GetLogger();
    logger->SetLogVerbosityLevel("low");
    logger->SetLogScreenLevel("warn");
    logger->SetColoredLog(true);

    // System paths
    const TString workDirectory = getenv("VMCWORKDIR");
    gSystem->Setenv("GEOMPATH", workDirectory + "/geometry");
    gSystem->Setenv("CONFIG_DIR", workDirectory + "/gconfig");

    // Output files
    const TString simufile = "test.simu.root";
    // const TString parafile = "test.para.root";

    // Basic simulation setup
    auto run = new FairRunSim();
    run->SetName("TGeant4");
    run->SetStoreTraj(false);
    run->SetMaterials("media_r3b.geo");
    run->SetSink(new FairRootFileSink(simufile));

    // Primary particle generator
    
  //  auto boxGen = new FairBoxGenerator(2212, 50);
   auto boxGen = new FairIonGenerator(6,12,6, 1, 0., 0., 400, 0., 0., -200.);
  boxGen->SetVertex(0,0,-200,1,1,0); 
    //boxGen->SetXYZ(0, 0, -100.);
   // boxGen->SetThetaRange(0, 10);
   // boxGen->SetPhiRange(0., 360.);
   // boxGen->SetEkinRange(0.2, 0.4);
    
  //auto boxGen=new  FairIonGenerator(1000060120, 1, 0,0,400, 0,0,-300);
  // auto boxGen =new FairIonGenerator(2212, 1, 0,0,200, 0,0,-300);
    
    
    auto primGen = new FairPrimaryGenerator();
    primGen->AddGenerator(boxGen);
    run->SetGenerator(primGen);

    // Geometry: Cave
    auto cave = new R3BCave("CAVE");
    cave->SetGeometryFileName("r3b_cave.geo");
    run->AddModule(cave);

    // Geometry: Alpide
    run->AddModule(new R3BAlpide("alpide_HIT202606.geo.root", { 0., 0., 0. }));
    auto rtdb = run->GetRuntimeDb();
    // Ascii file
    auto parIo = new FairParAsciiFileIo();
    auto parList = new TList();
    //parList->Add(new TObjString(pardir + "/alpide/alpide_mapping_v1.par"));
    parList->Add(new TObjString("./alpide_mapping.hh"));
    parIo->open(parList, "in");
    rtdb->setFirstInput(parIo);

    // Digitizer: Alpide
    auto digi = new R3BAlpideDigitizer("Alpide");
    digi->SetLabframe();
 
digi->SetGeoVersion(202606);
   run->AddTask(digi);



    // Init
    run->Init();

    // Simulate
    run->Run(nbevents);

    // Report
    timer.Stop();
    std::cout << "Real time: " << timer.RealTime() << "s, CPU time: " << timer.CpuTime() << "s" << std::endl;
    std::cout << "Macro finished successfully." << std::endl;
}
