#ifndef base_data_processor_h
#define base_data_processor_h

#include <iostream>

#include "BaseConfigurationObject.h"
#include "BaseDataObject.h"
#include "BaseNode.h"
#include "BaseProcessorResult.h"

class BaseDataProcessor : public BaseNode {
 public:

  BaseProcessorResult *processDataObject(BaseDataObject *dataObject);

  bool configure(BaseConfigurationObject *configObject); 

};


#endif
