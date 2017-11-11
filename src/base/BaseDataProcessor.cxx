#ifndef base_data_processor_cxx 
#define base_data_processor_cxx 

#include <iostream>

#include "BaseConfigurationObject.h"
#include "BaseDataObject.h"
#include "BaseDataProcessor.h"
#include "BaseProcessorResult.h"
#include "Types.h"

BaseDataProcessor::BaseDataProcessor(){
  fNodeType = node_types::processor; 
}

BaseProcessorResult * BaseDataProcessor::processDataObject(BaseDataObject *dataObject){
  std::cout << "[BaseDataProcessor::processDataObject] Base process method called, returning empty result. " << std::endl; 
  return new BaseProcessorResult(); 
}

#endif
