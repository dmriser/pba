#ifndef base_data_object_h
#define base_data_object_h

#include <iostream>

class BaseDataObject {  

 public:
  std::string getId() const {
    return fId; 
  }

 protected:
  std::string fId; 

};

#endif
