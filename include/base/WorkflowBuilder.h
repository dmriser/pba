#ifndef workflow_builder_h
#define workflow_builder_h

#include <iostream>
#include <vector>

#include "Factory.h"
#include "Workflow.h"

#include "json.hpp"
using json = nlohmann::json; 

class WorkflowBuilder {
 public:
  WorkflowBuilder(); 
  ~WorkflowBuilder(); 

  Workflow *getWorkflow(json *jsonInput, Factory *factory);
};

#endif
