#ifndef base_node_cxx
#define base_node_cxx

#include "BaseConfigurationObject.h"
#include "BaseNode.h"

BaseNode::BaseNode(){

}

BaseNode::~BaseNode(){

}

bool BaseNode::configure(BaseConfigurationObject *configObject){
// failing by default 
return false; 
}

 
#endif
