#ifndef factory_h 
#define factory_h 

#include <iostream>
#include <map>

#include "BaseDataAggregator.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"

#include "VectorFloatAnalysis.h"
#include "VectorFloatCut.h"
#include "VectorFloatProducer.h"


class Factory {

 public:
  Factory();
  ~Factory(); 

  static BaseDataAggregator * getAggregatorInstance(std::string id); 
  static BaseDataProducer   * getProducerInstance(std::string id); 
  static BaseDataProcessor  * getProcessorInstance(std::string id); 
};

#endif
