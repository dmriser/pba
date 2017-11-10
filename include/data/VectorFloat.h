#ifndef vector_float_h 
#define vector_float_h 

#include <iostream>
#include <vector>

#include "BaseDataObject.h"

class VectorFloat : public BaseDataObject {
  
 public:
  VectorFloat();
  ~VectorFloat(); 

  std::vector<float> data; 
};

#endif
