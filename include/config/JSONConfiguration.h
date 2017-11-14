#ifndef json_configuration_h 
#define json_configuration_h 

#include <iostream>

#include "BaseConfigurationObject.h"

#include "json.hpp"
using json = nlohmann::json; 

class JSONConfiguration : public BaseConfigurationObject {

 public:
  JSONConfiguration(); 
  ~JSONConfiguration(); 

  void setDatabase(std::string jsonFile);
  json fDatabase;
};

#endif
