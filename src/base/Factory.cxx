#ifndef factory_cxx 
#define factory_cxx 

#include <iostream>

#include "Factory.h"
#include "BaseNode.h"
#include "BaseDataAggregator.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"
#include "NullTypes.h"

#include "VectorFloatAnalysis.h"
#include "VectorFloatCut.h"
#include "VectorFloatProducer.h"

Factory::Factory(){

}

Factory::~Factory(){

}

BaseDataAggregator *Factory::getAggregatorInstance(std::string id){

  if(id == "VectorFloatAnalysis"){
    return new VectorFloatAnalysis(); 
  }
  else {
    std::cout << "[Factory::getAggregatorInstance] Id not found " << id << std::endl; 
    return new NullAggregator(); 
  }

  return new NullAggregator(); 
}

BaseDataProducer *Factory::getProducerInstance(std::string id){

  if(id == "VectorFloatProducer"){
    return new VectorFloatProducer(); 
  }
  else {
    std::cout << "[Factory::getProducerInstance] Id not found " << id << std::endl; 
    return new NullProducer(); 
  }

  return new NullProducer(); 
}

BaseDataProcessor *Factory::getProcessorInstance(std::string id){
  if(id == "VectorFloatCut"){
    return new VectorFloatCut(); 
  }
  else{
    std::cout << "[Factory::getProcessorInstance] Id not found " << id << std::endl; 
    return new NullProcessor(); 
  }

  return new NullProcessor(); 
}

#endif
