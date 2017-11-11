#ifndef vector_float_cut_cxx 
#define vector_float_cut_cxx 

#include "VectorFloat.h"
#include "VectorFloatCut.h"
#include "BaseProcessorResult.h"

VectorFloatCut::VectorFloatCut(){
  fCutValue = 0.5; 
}

VectorFloatCut::~VectorFloatCut(){

}

BaseProcessorResult *VectorFloatCut::processDataObject(BaseDataObject *dataObject){
  
  VectorFloat *vectorFloat = dynamic_cast<VectorFloat*>(dataObject); 

  for(std::vector<float>::iterator it = vectorFloat->data.begin(); it != vectorFloat->data.end(); ){
    if ((*it) < fCutValue){
      it = vectorFloat->data.erase(it); 
    }
    else {
      ++it; 
    }
  }

  return new BaseProcessorResult(); 
}

#endif
