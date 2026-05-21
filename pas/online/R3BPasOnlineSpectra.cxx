/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// ------------------------------------------------------------
// -----      R3BSingleAlpideCorrelationOnlineSpectra     -----
// -----    Created 21/05/2026	L.Rose		          -----
// ----- Fill Basic histograms for Pas			  -----
// ------------------------------------------------------------

#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

#include "R3BAlpideHitData.h"
#include "R3BEventHeader.h"
#include "R3BLogger.h"
#include "R3BPasOnlineSpectra.h"

#include "TCanvas.h"
#include "TClonesArray.h"
#include "TFolder.h"
#include "THttpServer.h"
#include "TMath.h"

//R3BHeaders
#include "R3BPasMappedData.h"
#include "R3BPasCalData.h"
#include "R3BPasHitData.h"
#include "R3BPasOnlineSpectra.h"
#include "R3BEventHeader.h"
#include "R3BLogger.h"
#include "R3BShared.h"

R3BPasOnlineSpectra::R3BPasOnlineSpectra(const TString &name, Int_t iVerbose )
	: FairTask(name, iVerbose)
{
}

R3BPasOnlineSpectra::~R3BPasOnlineSpectra() { R3BLOG(debug1, ""); }

InitStatus R3BPasOnlineSpectra::Init()
{
	R3BLOG(info, "");
	FairRootManager*mgr = FairRootManager::Instance();
	R3BLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

	FairRunOnline* run = FairRunOnline::Instance();
	run->GetHttpServer()->Register("", this);

	fMappedItems = dynamic_cast<TClonesArray*>(mgr->GetObject("PasMappedData"));
	fCalItems = dynamic_cast<TClonesArray*>(mgr->GetObject("PasCalData"));
	fHitItems = dynamic_cast<TClonesArray*>(mgr->GetObject("PasHitData"));
	/*
	//This is too strong->Could be missing?? 
	if (!fMappedItems)
	{
	R3BLOG(fatal, "PasMappedData not found");
	return kFATAL;
	}
	*/

	//Start filling histograms here for monitoring->Detector Geom

	//Mapped



    return kSUCCESS;
}


void R3BPasOnlineSpectra::Exec(Option_t*option)
{
	//Fill Mapped data
	if(fMappedItems && fMappedItems->GetEntriesFast()>0)
	{
		auto nHits=fMappedItems->GetEntriesFast();
		for(Int_t ihit=0;ihit<nHits;ihit++)
		{
			auto hit=dynamic_cast<R3BPasMappedData*>(fMappedItems->At(ihit));
			if(!hit)
			{
				continue;
			}
			//Specfic veto condition here for getting data such that its useful
			//Then fill your mapped level histograms


		}

	}
	if(fCalItems && fCalItems->GetEntriesFast()>0)
	{
		auto nHits=fCalItems->GetEntriesFast();
		for(Int_t ihit=0;ihit<nHits;ihit++)
		{
			auto hit=dynamic_cast<R3BPasCalData*>(fCalItems->At(ihit));
			if(!hit)
			{
				continue;
			}
			//Specific veto here or just fill cal histograms
		}

	}	
	if(fHitItems && fHitItems->GetEntriesFast()>0)
	{	
		auto nHits=fHitItems->GetEntriesFast();
		for(Int_t ihit = 0 ; ihit<nHits;ihit++)
		{
			auto hit=dynamic_cast<R3BPasHitData*>(fHitItems->At(ihit));
			if(!hit)
			{
				continue;
			}
			//Specifivc veto here or just fill hit histograms
		}

	}

}




void R3BPasOnlineSpectra::FinishEvent()
{
	if(fMappedItems)
	{
		fMappedItems->Clear();
	}	
	if(fCalItems)
	{
		fCalItems->Clear();
	}
	if(fHitItems)
	{
		fHitItems->Clear();
	}
}

void R3BPasOnlineSpectra::FinishTask()
{	
	if(fMappedItems)
	{
		//Here write map histograms to root file hist->Write();
	}
	if(fCalItems)
	{
		//Here write cal histograms to root file hist->Write();
	}
	if(fHitItems)
	{
		//Here write hit histograms to root file hist->Write();
	}



}







