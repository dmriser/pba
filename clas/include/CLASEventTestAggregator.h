#ifndef clas_event_test_aggregator_h
#define clas_event_test_aggregator_h

#include <iostream>

#include "BaseConfigurationObject.h"
#include "BaseDataAggregator.h"
#include "BaseDataObject.h"
#include "CLASEvent.h"

#include "json.hpp"
using json = nlohmann::json; 

// cern root includes 
#include "TH1.h"
#include "TH2.h"

class CLASEventTestAggregator : public BaseDataAggregator {
 public:
  CLASEventTestAggregator(); 
  ~CLASEventTestAggregator(); 

  bool configure(BaseConfigurationObject *config); 
  bool setOptions(json j); 
  void aggregate(BaseDataObject *dataObject);
  void finish(); 

  TH1F *h_p; 
  TH2F *h2_rphi_theta; 
  TH2F *h2_p_etot; 

 protected:
  std::string fOutputFile; 
};

#endif
