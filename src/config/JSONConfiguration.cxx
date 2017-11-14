#ifndef json_configuration_cxx 
#define json_configuration_cxx 

#include <iostream>
#include <fstream>

#include "JSONConfiguration.h"

#include "json.hpp"
using json = nlohmann::json; 

JSONConfiguration::JSONConfiguration(){
}

JSONConfiguration::~JSONConfiguration(){
}

void JSONConfiguration::setDatabase(std::string jsonFile){
  std::ifstream inputFile; 
  inputFile.open(jsonFile.c_str()); 
  
  if(inputFile.is_open()){
    json j; 
    inputFile >> j;
    fDatabase = j; 
  } else {
    std::cout << "[JSONConfiguration::setDatabase] trouble opening file " << jsonFile << std::endl; 
  }
}

#endif
