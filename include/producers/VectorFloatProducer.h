#ifndef vector_float_producer_h 
#define vector_float_producer_h 

#include "BaseDataProducer.h"
#include "Factory.h"
#include "VectorFloat.h"


// cern root includes 
#include "TRandom3.h"

// other external includes 
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

private:
  static ProducerRegister<VectorFloatProducer> addToFactory;
};

// this line is adding to factory so that the object can be built from configuration files 
ProducerRegister<VectorFloatProducer> VectorFloatProducer::addToFactory("VectorFloatProducer"); 

#endif
