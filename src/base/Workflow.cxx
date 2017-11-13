#ifndef workflow_cxx
#define workflow_cxx

#include "BaseDataAggregator.h"
#include "BaseDataProcessor.h"
#include "BaseDataProducer.h"
#include "Workflow.h"

Workflow::Workflow(){
}

Workflow::~Workflow(){
}

void Workflow::execute(){
  
  while(fProducer->hasDataObject()){
    BaseDataObject *dataObject = fProducer->getDataObject(); 

    // trickle down through processors 
    bool aggregateStatus = true; 

    for(BaseDataProcessor *processor : fProcessors){
      if(!processor->processDataObject(dataObject)->isPassed()){
	aggregateStatus = false; 
	break;
      }
    }

    // for the events which pass - aggregate
    if(aggregateStatus){
      for(BaseDataAggregator *aggregator : fAggregators){
	aggregator->aggregate(dataObject);
      }
    }
  }

  // finish aggregators 
  for(BaseDataAggregator *aggregator : fAggregators){
    aggregator->finish();
  }
  

}

#endif
