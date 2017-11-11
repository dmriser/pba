
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


int main(int argc, char *argv[]){
  
  // testing producer 
  //  VectorFloatProducer *producer = new VectorFloatProducer(); 
  BaseDataProducer *producer = Factory::getProducerInstance("VectorFloatProducer"); 
  

  // testing simple aggregator 
  //  VectorFloatAnalysis *analysis = new VectorFloatAnalysis(); 
  BaseDataAggregator *analysis = Factory::getAggregatorInstance("VectorFloatAnalysis");

  // testing simple cut 
  //  VectorFloatCut *processor = new VectorFloatCut(); 
  BaseDataProcessor *processor = Factory::getProcessorInstance("VectorFloatCut"); 

  for(int i=0; i<10; i++){
    if(producer->hasDataObject()){
      BaseDataObject *data = producer->getDataObject(); 
      processor->processDataObject(data); 
      analysis->aggregate(data); 
    }
  }

  return 0; 
}
