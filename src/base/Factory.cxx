#ifndef factory_cxx 
#define factory_cxx 

#include <iostream>

#include "Factory.h"
#include "BaseNode.h"
#include "BaseDataAggregator.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"
#include "NullTypes.h"

// vector float used for testing 
#include "VectorFloatAnalysis.h"
#include "VectorFloatCut.h"
#include "VectorFloatProducer.h"

Factory::Factory(){

}

Factory::~Factory(){

}

BaseDataAggregator *Factory::getAggregatorInstance(std::string id){

  if(Factory::getAggregatorRegistry().count(id) == 1){
    return Factory::getAggregatorRegistry()[id]; 
  }

  else {
    std::cout << "[Factory::getAggregatorInstance] Id not found " << id << std::endl; 
    return new NullAggregator(); 
  }

  return new NullAggregator(); 
}

BaseDataProducer *Factory::getProducerInstance(std::string id){

  if(Factory::getProducerRegistry().count(id) == 1){
    return Factory::getProducerRegistry()[id]; 
  }

  else {
    std::cout << "[Factory::getProducerInstance] Id not found " << id << std::endl; 
    return new NullProducer(); 
  }

  return new NullProducer(); 
}

BaseDataProcessor *Factory::getProcessorInstance(std::string id){

  if(Factory::getProcessorRegistry().count(id) == 1){
    return Factory::getProcessorRegistry()[id]; 
  }


  else{
    std::cout << "[Factory::getProcessorInstance] Id not found " << id << std::endl; 
    return new NullProcessor(); 
  }

  return new NullProcessor(); 
}

#endif
