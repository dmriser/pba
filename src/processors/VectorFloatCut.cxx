#ifndef vector_float_cut_cxx 
#define vector_float_cut_cxx 

#include "VectorFloat.h"
#include "VectorFloatCut.h"
#include "BaseProcessorResult.h"
#include "BaseConfigurationObject.h"
#include "JSONConfiguration.h"

#include "json.hpp"
using json = nlohmann::json; 

VectorFloatCut::VectorFloatCut(){
  fId = "VectorFloatCut";
  fCutMin = 0.0; 
  fCutMax = 1.0; 
}

VectorFloatCut::~VectorFloatCut(){

}

BaseProcessorResult *VectorFloatCut::processDataObject(BaseDataObject *dataObject){
  
  VectorFloat *vectorFloat = dynamic_cast<VectorFloat*>(dataObject); 

  for(std::vector<float>::iterator it = vectorFloat->data.begin(); it != vectorFloat->data.end(); ){
    if ((*it) < fCutMin || (*it) > fCutMax){
      it = vectorFloat->data.erase(it); 
    }
    else {
      ++it; 
    }
  }

  BaseProcessorResult *result = new BaseProcessorResult(); 
  result->setIsPassed(true); 
  return result; 
}

bool VectorFloatCut::configure(BaseConfigurationObject *config){

  JSONConfiguration *conf = static_cast<JSONConfiguration*>(config); 
  std::vector<json> db = conf->fDatabase.at("data").get<std::vector<json>>(); 

  for(json j : db){
    if(j.at("run_number").get<int>() == 0){
      fCutMin = j.at("vector_float_cut_min").get<float>();
      fCutMax = j.at("vector_float_cut_max").get<float>();
    }
  }

  return false; 
}

#endif
