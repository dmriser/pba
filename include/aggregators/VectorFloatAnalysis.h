#ifndef vector_float_analysis_h
#define vector_float_analysis_h

#include <iostream>
#include <vector>

#include "BaseDataAggregator.h"
#include "VectorFloat.h"

class VectorFloatAnalysis : public BaseDataAggregator {
 public:
  VectorFloatAnalysis();
  ~VectorFloatAnalysis();


  void aggregate(VectorFloat *vec);
  void finish(); 

};

#endif
