
#include <iostream>


#include "BaseNode.h"
#include "BaseDataAggregator.h"
#include "BaseDataObject.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"
#include "Factory.h"
#include "VectorFloat.h"
#include "VectorFloatAnalysis.h"
#include "VectorFloatCut.h"
#include "VectorFloatProducer.h"
#include "Workflow.h"
#include "WorkflowBuilder.h"

int main(int argc, char *argv[]){
  
  // testing producer 
  BaseDataProducer *producer = Factory::getProducerInstance("VectorFloatProducer"); 
  

  // testing simple aggregator 
  BaseDataAggregator *aggregator = Factory::getAggregatorInstance("VectorFloatAnalysis");

  // testing simple cut 
  BaseDataProcessor *processor = Factory::getProcessorInstance("VectorFloatCut"); 


  Workflow *workflow = new Workflow(); 
  workflow->setDataProducer(producer); 
  workflow->addDataProcessor(processor); 
  workflow->addDataAggregator(aggregator); 
  workflow->execute(); 

  return 0; 
}
