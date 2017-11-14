#include <iostream>
#include <fstream>

#include "json.hpp"
using json = nlohmann::json; 

int main(int argc, char *argv[]){

  if(argc < 2){
    std::cout << "please pass in the json file to validate" << std::endl; 
    exit(0);
  }

  std::ifstream input;
  input.open(argv[1]);

  if(input.is_open()){
    json j; 
    input >> j; 

    std::cout << j.dump() << std::endl; 
  } else {
    std::cout << "trouble opening json file provided." << std::endl; 
  }

  return 0; 
}
