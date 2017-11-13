#ifndef database_h 
#define database_h 

#include <iostream>
#include <map>

class DataBase {
 public:
  DataBase(); 
  ~DataBase(); 

 protected:
  std::map<std::string, std::string> fFields; 

};

#endif
