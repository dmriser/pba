#ifndef base_data_processor_cxx 
#define base_data_processor_cxx 

#include <iostream>

#include "BaseConfigurationObject.h"
#include "BaseDataObject.h"
#include "BaseDataProcessor.h"
#include "BaseProcessorResult.h"

BaseProcessorResult * BaseDataProcessor::processDataObject(BaseDataObject *dataObject){
  std::cout << "[BaseDataProcessor::processDataObject] Base process method called, returning empty result. " << std::endl; 
  return new BaseProcessorResult(); 
}

bool BaseDataProcessor::configure(BaseConfigurationObject *configObject){
  std::cout << "[BaseDataProcessor::configure] Base configuration method called, returning false. " << std::endl; 
  return false; 
}

#endif
