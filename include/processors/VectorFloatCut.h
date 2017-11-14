#ifndef vector_float_cut_h
#define vector_float_cut_h

#include "BaseDataProcessor.h"
#include "BaseProcessorResult.h"

class VectorFloatCut : public BaseDataProcessor {
 public:
  VectorFloatCut(); 
  ~VectorFloatCut(); 

  BaseProcessorResult *processDataObject(BaseDataObject *dataObject); 

  void setCutMin(float min){
    fCutMin = min; 
  }
  
  void setCutMax(float max){
    fCutMax = max; 
  }

  float getCutMin() const {
    return fCutMin; 
  } 

  float getCutMax() const {
    return fCutMax; 
  } 

 protected:
  float fCutMin, fCutMax; 

};

#endif
