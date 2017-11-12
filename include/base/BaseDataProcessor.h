#ifndef base_data_processor_h
#define base_data_processor_h

#include <iostream>

#include "BaseConfigurationObject.h"
#include "BaseDataObject.h"
#include "BaseNode.h"
#include "BaseProcessorResult.h"

class BaseDataProcessor : public BaseNode {
 public:
  BaseDataProcessor(); 
  virtual BaseProcessorResult *processDataObject(BaseDataObject *dataObject);
};


#endif
