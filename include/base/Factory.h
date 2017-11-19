#ifndef factory_h 
#define factory_h 

#include <iostream>
#include <unordered_map>
#include <functional>

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

  typedef std::unordered_map<std::string, std::function<BaseDataAggregator*()> > aggregator_registry; 
  typedef std::unordered_map<std::string, std::function<BaseDataProcessor*()> >  processor_registry; 
  typedef std::unordered_map<std::string, std::function<BaseDataProducer*()> >   producer_registry; 

  static BaseDataAggregator & getAggregatorRegistry(){
    static aggregator_registry reg;
    return reg;
  }

  static BaseDataProducer & getProducerRegistry(){
    static producer_registry reg;
    return reg;
  }

  static BaseDataProcessor & getProcessorRegistry(){
    static processor_registry reg;
    return reg;
  }

  static BaseDataAggregator * getAggregatorInstance(std::string id); 
  static BaseDataProducer   * getProducerInstance(std::string id); 
  static BaseDataProcessor  * getProcessorInstance(std::string id); 
};

template<typename T> struct AggregatorRegister {
  AggregatorRegister(std::string id){
    Factory::getAggregatorRegistry()[name] = []() { return new T; };
    std::cout << "[Factory::AggregatorRegister] Registering class '" << name << "'\n";
  }
} 

template<typename T> struct ProducerRegister {
  ProducerRegister(std::string id){
    Factory::getProducerRegistry()[name] = []() { return new T; };
    std::cout << "[Factory::ProducerRegister] Registering class '" << name << "'\n";
  }
} 

template<typename T> struct ProcessorRegister {
  ProcessorRegister(std::string id){
    Factory::getProcessorRegistry()[name] = []() { return new T; };
    std::cout << "[Factory::ProcessorRegister] Registering class '" << name << "'\n";
  }
} 

#endif
