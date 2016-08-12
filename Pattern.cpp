#include "Pattern.hpp"

// constructor
Pattern::Pattern(std::string const param){
  bool ok = ((param.find(PATTERN_NAME) != std::string::npos)
    && (param.find(PATTERN_UML) != std::string::npos)
    && (param.find(PATTERN_RESUME) != std::string::npos)
    && (param.find(PATTERN_DESCRIPTION) != std::string::npos));

  if(ok){
    std::cout << "param seems correct" << std::endl;
  }
}

// destructor
Pattern::~Pattern(){
}

// returns pattern's informations
std::string const Pattern::getInformations(){
 std::stringstream res;
 // TODO
 return res.str();
}
