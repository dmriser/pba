#ifndef base_data_aggregator_h
#define base_data_aggregator_h

#include "BaseNode.h"

class BaseDataAggregator : public BaseNode {

 public:
  BaseDataAggregator();
  ~BaseDataAggregator();

  virtual void aggregate(BaseDataObject *dataObject);
  virtual void finish();

};

#endif
