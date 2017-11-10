#ifndef base_data_producer_cxx 
#define base_data_producer_cxx 

#include <iostream>

#include "BaseDataObject.h"
#include "BaseDataProducer.h"
#include "Types.h"

BaseDataProducer::BaseDataProducer(){
  fNodeType = node_types::producer; 
}

BaseDataProducer::~BaseDataProducer(){

}

#endif
