#ifndef vector_float_producer_h 
#define vector_float_producer_h 

#include "BaseDataProducer.h"
#include "VectorFloat.h"

#include "TRandom3.h"

class VectorFloatProducer : public BaseDataProducer {

 public:
  VectorFloatProducer();
  ~VectorFloatProducer();

  VectorFloat *getDataObject();
  bool         hasDataObject(); 

 protected:
  TRandom3 fRandom; 

};

#endif
