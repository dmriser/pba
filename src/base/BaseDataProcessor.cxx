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

BaseProcessorResult *BaseDataProcessor::processDataObject(BaseDataObject *dataObject){
  return new BaseProcessorResult(); 
}

#endif
