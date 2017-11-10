#ifndef data_processor_factory 
#define data_processor_factory

#include <iostream>

#include "BaseDataProcessor.h"

class DataProcessorFactory {

 public:
  DataProcessorFactory();
  ~DataProcessorFactory();

  BaseDataProcessor *getDataProcessor(std::string id);

};

#endif
