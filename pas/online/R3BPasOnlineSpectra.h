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

#pragma once

#include <FairTask.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TMath.h>

class TClonesArray;
class R3BEventHeader;


//Det name 
class R3BPasOnlineSpectra : public FairTask
{
	public:
		R3BPasOnlineSpectra(const TString& name,Int_t iVerbose = 1);



		virtual ~R3BPasOnlineSpectra();
		/**
		 * Method for task initialization.
		 * This function is called by the framework before
		 * the event loop.
		 * @return Initialization status. kSUCCESS, kERROR or kFATAL.
		 */
		virtual InitStatus Init();

		/**
		 * Method for event loop implementation.
		 * Is called by the framework every time a new event is read.
		 * @param option an execution option.
		 */
		virtual void Exec(Option_t* option);

		/**
		 * A method for finish of processing of an event.
		 * Is called by the framework for each event after executing
		 * the tasks.
		 */
		virtual void FinishEvent();

		/**
		 * Method for finish of the task execution.
		 * Is called by the framework after processing the event loop.
		 */	
		virtual void FinishTask();

		/**
		 * Methods to clean histograms.
		 */
		virtual void Reset_Histo();	

	private:
		TClonesArray*fMappedItems=nullptr;
		TClonesArray*fCalItems=nullptr;
		TClonesArray*fHitItems=nullptr;
		R3BEventHeader* header=nullptr; /**< Event header.      */
		Int_t fNEvents;         /**< Event counter.     */
		Int_t fId1, fId2;
		TString fNameDet1, fNameDet2;
		//Canvas

		//Histograms


	public:
		ClassDef(R3BPasOnlineSpectra,1)	
};

