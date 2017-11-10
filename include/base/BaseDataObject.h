#ifndef base_data_object_h
#define base_data_object_h

#include <iostream>

class BaseDataObject {  

 public:
  BaseDataObject(); 
  virtual ~BaseDataObject(); 

  std::string getId() const {
    return fId; 
  }

 protected:
  std::string fId; 

};

#endif
