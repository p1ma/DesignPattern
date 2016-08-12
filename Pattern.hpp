#ifndef PATTERN
#define PATTERN

#include <string>
#include <iostream>
#include <sstream>

#define PATTERN_NAME "@NAME"
#define PATTERN_UML "@UML"
#define PATTERN_RESUME "@RESUME_FROM"
#define PATTERN_DESCRIPTION "@DESCRIPTION"

class Pattern{

private :
  std::string name; // pattern's name
  std::string image_name; // pattern's image name
  std::string url_informations; // url to pattern's informations 
  std::string description; // pattern's description
public :
  Pattern(std::string const param); // constructor
  ~Pattern(); // destructor
  std::string const getInformations(); // pattern's informations

};

#endif // PATTERN
