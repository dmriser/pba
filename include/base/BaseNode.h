#ifndef base_node_h
#define base_node_h

#include <iostream>

#include "BaseConfigurationObject.h"

#include "json.hpp"
using json = nlohmann::json; 

class BaseNode {

 public:
  BaseNode(); 
  ~BaseNode(); 

  virtual bool configure(BaseConfigurationObject *configObject);
  virtual bool setOptions(json j);

  void setId(const std::string & id){
    fId = id; 
  }

  std::string getId() const {
    return fId; 
  }

  int getNodeType() const {
    return fNodeType; 
  }

 protected:
  std::string fId; 
  int         fNodeType; 
};

#endif
