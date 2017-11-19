#ifndef vector_float_analysis_h
#define vector_float_analysis_h

#include <iostream>
#include <vector>

#include "BaseDataObject.h"
#include "BaseDataAggregator.h"
#include "Factory.h"
#include "VectorFloat.h"

class VectorFloatAnalysis : public BaseDataAggregator {
 public:
  VectorFloatAnalysis();
  ~VectorFloatAnalysis();

  void aggregate(BaseDataObject *dataObject) override;
  void finish() override; 

 protected:
  float fMean, fVar;

 private:
  static AggregatorRegister<VectorFloatAnalysis> addToFactory; 

};

AggregatorRegister<VectorFloatAnalysis> VectorFloatAnalysis::addToFactory("VectorFloatAnalysis"); 

#endif
