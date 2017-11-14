#ifndef base_data_producer_h
#define base_data_producer_h 

#include "BaseDataObject.h"
#include "BaseNode.h"

class BaseDataProducer : public BaseNode {

 public:
  BaseDataProducer(); 
  ~BaseDataProducer(); 

  virtual BaseDataObject *getDataObject() = 0;
  virtual bool            hasDataObject() = 0; 
  virtual bool            requestsConfiguration() = 0; 
};

#endif
