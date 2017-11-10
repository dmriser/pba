#ifndef base_node_h
#define base_node_h

#include <iostream>

class BaseNode {

 public:

  void setId(const std::string & id){
    fId = id; 
  }

  std::string getId() const {
    return fId; 
  }

  int getNodeType() const {
    return fNodeType; 
  }

 protected:
  std::string fId; 
  int         fNodeType; 
};

#endif
