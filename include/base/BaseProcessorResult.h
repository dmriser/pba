#ifndef base_processor_result_h
#define base_processor_result_h

#include <iostream>

class BaseProcessorResult {

 public:

  std::string getId() const {
    return fId; 
  }

 protected:
  std::string fId;
  
};

#endif
