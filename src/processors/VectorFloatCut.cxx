#ifndef vector_float_cut_cxx 
#define vector_float_cut_cxx 

#include "VectorFloat.h"
#include "VectorFloatCut.h"
#include "BaseProcessorResult.h"

VectorFloatCut::VectorFloatCut(){
  fId = "VectorFloatCut";
  fCutMin = 0.0; 
  fCutMax = 1.0; 
}

VectorFloatCut::~VectorFloatCut(){

}

BaseProcessorResult *VectorFloatCut::processDataObject(BaseDataObject *dataObject){
  
  VectorFloat *vectorFloat = dynamic_cast<VectorFloat*>(dataObject); 

  for(std::vector<float>::iterator it = vectorFloat->data.begin(); it != vectorFloat->data.end(); ){
    if ((*it) < fCutMin || (*it) > fCutMax){
      it = vectorFloat->data.erase(it); 
    }
    else {
      ++it; 
    }
  }

  BaseProcessorResult *result = new BaseProcessorResult(); 
  result->setIsPassed(true); 
  return result; 
}

#endif
