#ifndef workflow_builder_cxx
#define workflow_builder_cxx 

#include <iostream>
#include <map>

#include "BaseDataProducer.h"
#include "Factory.h"
#include "JSONConfiguration.h"
#include "Workflow.h"
#include "WorkflowBuilder.h"

#include "json.hpp"
using json = nlohmann::json; 

WorkflowBuilder::WorkflowBuilder(){
}

WorkflowBuilder::~WorkflowBuilder(){
}

Workflow *WorkflowBuilder::getWorkflow(json *jsonInput){

  // check for structure 
  if(jsonInput->count("nodes") != 1){
    std::cerr << "[WorkflowBuilder::getWorkflow] JSON input file doesn't contain nodes section." << std::endl; 
    exit(0); 
  }

  json nodes = jsonInput->at("nodes").get<json>(); 

  // run basic failure checks
  if(nodes.count("producer") != 1){
    std::cerr << "[WorkflowBuilder::getWorkflow] workflow doesn't specify a producer, use producer to add one." << std::endl; 
    exit(0); 
  }

  if(nodes.count("aggregators") < 1){
    std::cerr << "[WorkflowBuilder::getWorkflow] workflow doesn't specify an aggregator, use aggregators to add one." << std::endl; 
    exit(0);
  }

  // get subsections of json file 
  json producer_json   = nodes.at("producer").get<json>(); 
  json aggregator_json = nodes.at("aggregators").get<std::vector<json> >();
  json processor_json  = nodes.at("processors").get<std::vector<json> >();   

  // check for meta-data
  if(jsonInput->count("metadata") != 1){
    std::cerr << "[WorkflowBuilder::getWorkflow] JSON input file doesn't contain metadata section." << std::endl; 
    exit(0); 
  }
  
  // retrieve metadata
  json metadata = jsonInput->at("metadata").get<json>();
  std::string databaseFile = metadata.at("database").get<std::string>();
  
  // setup configuration 
  JSONConfiguration *jsonDatabase = new JSONConfiguration();
  jsonDatabase->setDatabase(databaseFile);

  // start building the workflow 
  Workflow *workflow = new Workflow(); 
  workflow->setConfigurationObject(jsonDatabase);

  BaseDataProducer *producer = Factory::getProducerInstance(producer_json.at("id").get<std::string>()); 
  workflow->setDataProducer(producer); 

  for(json j : aggregator_json){
    BaseDataAggregator *aggregator = Factory::getAggregatorInstance(j.at("id").get<std::string>()); 
    workflow->addDataAggregator(aggregator);     
  }

  for(json j : processor_json){
    BaseDataProcessor *processor = Factory::getProcessorInstance(j.at("id").get<std::string>()); 
    workflow->addDataProcessor(processor);     
  }
  
  workflow->printWorkflowDiagram(); 
  return workflow; 
}

#endif
