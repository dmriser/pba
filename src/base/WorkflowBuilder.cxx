#ifndef workflow_builder_cxx
#define workflow_builder_cxx 

#include "Factory.h"
#include "Workflow.h"
#include "WorkflowBuilder.h"

#include "json.hpp"
using json = nlohmann::json; 

WorkflowBuilder::WorkflowBuilder(){

}

WorkflowBuilder::~WorkflowBuilder(){

}

Workflow *WorkflowBuilder::getWorkflow(json *jsonConfig, Factory *factory){
  
  return new Workflow(); 
}

#endif
