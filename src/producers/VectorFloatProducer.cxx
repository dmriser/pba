#ifndef vector_float_producer_cxx
#define vector_float_producer_cxx

#include <iostream>
#include <vector>

#include "VectorFloatProducer.h"

VectorFloatProducer::VectorFloatProducer(){
  fId = "VectorFloatProducer"; 
}

VectorFloat * VectorFloatProducer::getDataObject(){
  VectorFloat *vec = new VectorFloat(); 
  
  for (int i=0; i<100000; i++){
    vec->data.push_back(fRandom.Uniform(1.0)); 
  }

  return vec; 
}

bool VectorFloatProducer::hasDataObject(){
  return true; 
}

#endif
