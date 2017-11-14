#ifndef workflow_cxx
#define workflow_cxx

#include "BaseConfigurationObject.h"
#include "BaseDataAggregator.h"
#include "BaseDataProcessor.h"
#include "BaseDataProducer.h"
#include "Types.h"
#include "Workflow.h"

Workflow::Workflow(){
}

Workflow::~Workflow(){
}

void Workflow::execute(){
  
  while(fProducer->hasDataObject()){

    // see if we need to configure the nodes 
    if(fProducer->requestsConfiguration()){
      fProducer->configure(fConfig);
      for(BaseDataProcessor *processor : fProcessors){ processor->configure(fConfig); }
      for(BaseDataAggregator *aggregator : fAggregators){ aggregator->configure(fConfig); }

      std::cout << "[Workflow::execute] producer " << fProducer->getId() << " has requested configuration.  " << std::endl; 
    }

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

void Workflow::printWorkflowDiagram(){
  printf("-----------------------------------------------------------------------------\n"); 
  printf("-----------------------------------------------------------------------------\n"); 
  printf("\n");
  printf("                               Workflow Diagram                              \n");
  printf("\n");
  printf("         ProducerNode -> %s                                                  \n", fProducer->getId().c_str());
  printf("                   \\ \n");

  for(BaseDataProcessor *p : fProcessors){
    printf("                 ProcessorNode -> %s                                          \n", p->getId().c_str());
  }
  printf("                         |\n");

  for(BaseDataAggregator *a : fAggregators){
    printf("                 AggregatorNode -> %s                                         \n", a->getId().c_str());
  }
  printf("\n");

  printf("-----------------------------------------------------------------------------\n"); 
  printf("-----------------------------------------------------------------------------\n"); 
}

void Workflow::setConfigurationObject(BaseConfigurationObject *config){
  fConfig = config; 
}

#endif
