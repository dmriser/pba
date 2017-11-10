#ifndef base_configuration_object
#define base_configuration_object

#include <iostream>

class BaseConfigurationObject {

 public:
  
  std::string getId() const {
    return fId; 
  }

 protected:
  std::string fId; 

};

#endif
