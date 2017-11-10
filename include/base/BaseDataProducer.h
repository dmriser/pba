#ifndef base_data_producer_h
#define base_data_producer_h 

#include "BaseDataObject.h"
#include "BaseNode.h"

class BaseDataProducer : public BaseNode {

 public:
  virtual BaseDataObject *getDataObject();
  virtual bool            hasDataObject(); 

};

#endif
