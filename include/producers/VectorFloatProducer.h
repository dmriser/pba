#ifndef vector_float_producer_h 
#define vector_float_producer_h 

#include "BaseDataProducer.h"
#include "VectorFloat.h"

#include "TRandom3.h"

#include "json.hpp"
using json = nlohmann::json; 

class VectorFloatProducer : public BaseDataProducer {

 public:
  VectorFloatProducer();
  ~VectorFloatProducer();

  VectorFloat *getDataObject();
  bool         hasDataObject(); 
  bool         requestsConfiguration();
  bool         setOptions(json j);

 protected:
  int      fLength, fIter, fIterMax; 
  TRandom3 fRandom; 

};

#endif
