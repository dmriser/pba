#ifndef data_processor_factory_cxx 
#define data_processor_factory_cxx 

#include "BaseDataProcessor.h"
#include "DataProcessorFactory.h"

DataProcessorFactory::DataProcessorFactory(){

}

DataProcessorFactory::~DataProcessorFactory(){

}

BaseDataProcessor * DataProcessorFactory::getDataProcessor(std::string id){
  return new BaseDataProcessor(); 
}

#endif
