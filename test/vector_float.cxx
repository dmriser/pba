
#include <iostream>


#include "BaseNode.h"
#include "BaseDataAggregator.h"
#include "BaseDataObject.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"

#include "VectorFloat.h"
#include "VectorFloatAnalysis.h"
#include "VectorFloatCut.h"
#include "VectorFloatProducer.h"


int main(int argc, char *argv[]){
  
  // testing producer 
  VectorFloatProducer *producer = new VectorFloatProducer(); 
  
  // testing simple aggregator 
  VectorFloatAnalysis *analysis = new VectorFloatAnalysis(); 

  // testing simple cut 
  VectorFloatCut *processor = new VectorFloatCut(); 

  for(int i=0; i<10; i++){
    if(producer->hasDataObject()){
      BaseDataObject *data = producer->getDataObject(); 
      processor->processDataObject(data); 
      analysis->aggregate(data); 
    }
  }

  return 0; 
}
