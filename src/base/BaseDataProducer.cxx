#ifndef base_data_producer_cxx 
#define base_data_producer_cxx 

#include <iostream>

#include "BaseDataObject.h"
#include "BaseDataProducer.h"

BaseDataObject * BaseDataProducer::getDataObject(){
  std::cout << "[BaseDataProducer::getDataObject] Base production method called, returning null. " << std::endl; 
  return new BaseDataObject(); 
}

#endif
