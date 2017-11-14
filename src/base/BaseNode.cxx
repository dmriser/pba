#ifndef base_node_cxx
#define base_node_cxx

#include "BaseConfigurationObject.h"
#include "BaseNode.h"

#include "json.hpp"
using json = nlohmann::json; 

BaseNode::BaseNode(){

}

BaseNode::~BaseNode(){

}

bool BaseNode::configure(BaseConfigurationObject *configObject){
// failing by default 
return false; 
}

bool BaseNode::setOptions(json j){
  return false; 
}
 
#endif
