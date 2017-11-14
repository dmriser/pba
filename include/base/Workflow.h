#ifndef workflow_h 
#define workflow_h 

#include <iostream>
#include <vector>

#include "BaseConfigurationObject.h"
#include "BaseDataAggregator.h"
#include "BaseDataProcessor.h"
#include "BaseDataProducer.h"

class Workflow {
 public:
  Workflow();
  ~Workflow(); 

  void execute(); 

  void setConfigurationObject(BaseConfigurationObject *config);

  void setDataProducer(BaseDataProducer *producer){
    fProducer = producer; 
  }

  void addDataProcessor(BaseDataProcessor *processor){
    fProcessors.push_back(processor);
  }
  
  void addDataAggregator(BaseDataAggregator *aggregator){
    fAggregators.push_back(aggregator); 
  }

  void printWorkflowDiagram(); 

 protected:
  BaseDataProducer *               fProducer; 
  std::vector<BaseDataProcessor*>  fProcessors; 
  std::vector<BaseDataAggregator*> fAggregators; 

  BaseConfigurationObject         *fConfig; 
};

#endif
