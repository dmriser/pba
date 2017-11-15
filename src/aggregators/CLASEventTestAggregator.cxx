#ifndef clas_event_test_aggregator_cxx
#define clas_event_test_aggregator_cxx

#include <iostream>

#include "BaseConfigurationObject.h"
#include "BaseDataAggregator.h"
#include "BaseDataObject.h"
#include "CLASEvent.h"
#include "CLASEventTestAggregator.h"

#include "json.hpp"
using json = nlohmann::json; 

// cern root includes 
#include "TFile.h"
#include "TH1.h"

CLASEventTestAggregator::CLASEventTestAggregator(){
  fId = "CLASEventTestAggregator";
  h_p = new TH1F("h_p", "h_p", 400, 0.0, 6.0); 
}

CLASEventTestAggregator::~CLASEventTestAggregator(){

}

bool CLASEventTestAggregator::configure(BaseConfigurationObject *config){
  return true; 
}

bool CLASEventTestAggregator::setOptions(json j){
  if(j.count("output_file") != 1){
    std::cerr << "[CLASEventTestAggregator::setOptions] Specify output_file in the options section. " << std::endl; 
    exit(0); 
  }
  fOutputFile = j.at("output_file").get<std::string>();
  return true; 
}

void CLASEventTestAggregator::aggregate(BaseDataObject *dataObject){
  CLASEvent *event = dynamic_cast<CLASEvent*>(dataObject);   

  for(int itrack=0; itrack<event->getNumberOfTracks(); itrack++){
    CLASTrack *track = event->getTrack(itrack);

    if(track->hasBank(bank_t::part)){
      PartBank *part = static_cast<PartBank*>(track->getBank(bank_t::part)); 
      h_p->Fill(part->p);
    }
  }
}

void CLASEventTestAggregator::finish(){
  std::cout << "[CLASEventTestAggregator::finish] finished with entries = " << h_p->GetEntries() << std::endl;

  TFile *outputFile = new TFile(fOutputFile.c_str(), "RECREATE"); 
  if(outputFile->IsOpen()){
    outputFile->cd("/"); 
    h_p->Write(); 
    outputFile->Close(); 
  }

}

#endif
