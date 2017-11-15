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

// clas event 
#include "CLASEvent.h"
#include "CLASEventProducer.h"
#include "CLASEventTestAggregator.h"

Factory::Factory(){

}

Factory::~Factory(){

}

BaseDataAggregator *Factory::getAggregatorInstance(std::string id){

  if(id == "VectorFloatAnalysis"){
    return new VectorFloatAnalysis(); 
  }

  else if (id == "CLASEventTestAggregator"){
    return new CLASEventTestAggregator();
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
  
  else if (id == "NT22CLASEventProducer"){
    return new NT22CLASEventProducer(); 
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
