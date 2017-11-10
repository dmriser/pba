#ifndef vector_float_analysis_cxx 
#define vector_float_analysis_cxx 

#include <iostream>
#include <vector>
#include <cmath>

#include "BaseDataObject.h"
#include "VectorFloat.h"
#include "VectorFloatAnalysis.h"

VectorFloatAnalysis::VectorFloatAnalysis(){
  fId = "VectorFloatAnalysis";
  fMean = 0; 
  fVar  = 0; 
}

VectorFloatAnalysis::~VectorFloatAnalysis(){
}

void VectorFloatAnalysis::aggregate(BaseDataObject *dataObject){

  VectorFloat *vectorFloat = dynamic_cast<VectorFloat*>(dataObject); 

  int n = vectorFloat->data.size(); 

  float sum = 0.0; 
  float sum2 = 0.0; 
  for(float f : vectorFloat->data){
    sum  += f; 
    sum2 += pow(f,2); 
  }

  fMean = sum/n; 
  fVar  = sum2/n - pow(fMean,2);


  printf("[VectorFloatAnalysis::aggregate] mean = %.3e, var = %.3e \n", fMean, fVar); 
}

void VectorFloatAnalysis::finish(){

}

#endif
