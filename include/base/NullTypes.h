#ifndef null_types_h 
#define null_types_h 

#include <iostream>

#include "BaseDataAggregator.h"
#include "BaseDataProducer.h"
#include "BaseDataProcessor.h"
#include "BaseDataObject.h"
#include "BaseProcessorResult.h"

class NullAggregator : public BaseDataAggregator {
 public:
  NullAggregator(){ } 
  ~NullAggregator(){ }
  void aggregate(BaseDataObject *dataObject){ }
  void finish(){ }
};

class NullProducer : public BaseDataProducer {
 public:
  NullProducer(){ }
  ~NullProducer(){ }
  BaseDataObject *getDataObject(){ return new BaseDataObject(); }
  bool hasDataObject(){ return false; }
};

class NullProcessor : public BaseDataProcessor {
 public:
  NullProcessor(){}
  ~NullProcessor(){}
  BaseProcessorResult *processDataObject(BaseDataObject *dataObject){ return new BaseProcessorResult(); }
};

#endif
