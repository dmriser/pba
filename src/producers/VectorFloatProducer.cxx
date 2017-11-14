#ifndef vector_float_producer_cxx
#define vector_float_producer_cxx

#include <iostream>
#include <vector>

#include "VectorFloatProducer.h"

VectorFloatProducer::VectorFloatProducer(){
  fId = "VectorFloatProducer"; 
  fIter = 0; 
}

VectorFloat * VectorFloatProducer::getDataObject(){
  fIter++; 

  VectorFloat *vec = new VectorFloat(); 
  
  for (int i=0; i<1000; i++){
    vec->data.push_back(fRandom.Uniform(1.0)); 
  }

  return vec; 
}

bool VectorFloatProducer::hasDataObject(){
  if (fIter > 10){
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

#endif
