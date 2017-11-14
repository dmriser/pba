#ifndef vector_float_producer_cxx
#define vector_float_producer_cxx

#include <iostream>
#include <vector>

#include "VectorFloatProducer.h"

#include "json.hpp"
using json = nlohmann::json; 

VectorFloatProducer::VectorFloatProducer(){
  fId = "VectorFloatProducer"; 
  fIter = 0; 
  fIterMax = 10; 
}

VectorFloat * VectorFloatProducer::getDataObject(){
  fIter++; 

  VectorFloat *vec = new VectorFloat(); 
  
  for (int i=0; i<fLength; i++){
    vec->data.push_back(fRandom.Uniform(1.0)); 
  }

  return vec; 
}

bool VectorFloatProducer::hasDataObject(){
  if (fIter > fIterMax){
    return false; 
  }

  return true; 
}

bool VectorFloatProducer::requestsConfiguration(){
  if (fIter < 1){
    return true;
  }

  return false; 
}

bool VectorFloatProducer::setOptions(json j){
  
  if(j.count("iterations") == 1){
    fIterMax = j.at("iterations").get<int>();
  }

  if(j.count("length") == 1){
    fLength = j.at("length").get<int>();
  }

  return false; 
}

#endif
