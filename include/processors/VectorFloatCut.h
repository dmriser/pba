#ifndef vector_float_cut_h
#define vector_float_cut_h

#include "BaseDataProcessor.h"
#include "BaseProcessorResult.h"

class VectorFloatCut : public BaseDataProcessor {
 public:
  VectorFloatCut(); 
  ~VectorFloatCut(); 

  BaseProcessorResult *processDataObject(BaseDataObject *dataObject); 

 protected:
  float fCutValue; 

};

#endif
