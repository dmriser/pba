
#include <iostream>
#include <fstream>

#include "BaseNode.h"
#include "BaseDataAggregator.h"
#include "BaseDataObject.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"
#include "Factory.h"
#include "VectorFloat.h"
#include "VectorFloatAnalysis.h"
#include "VectorFloatCut.h"
#include "VectorFloatProducer.h"
#include "Workflow.h"
#include "WorkflowBuilder.h"

#include "json.hpp"
using json = nlohmann::json; 

int main(int argc, char *argv[]){
  
  if(argc < 2){
    std::cerr << "[workflow::main] please pass in the test json file." << std::endl; 
    exit(0); 
  }

  std::ifstream inputFile; 
  inputFile.open(argv[1]); 

  if(inputFile.is_open()){
    json j;
    inputFile >> j; 


    Workflow *workflow = WorkflowBuilder::getWorkflow(&j); 
    workflow->execute(); 

  } else {
    std::cerr << "[workflow::main] error opening json file. " << std::endl; 
  }

  return 0; 
}
