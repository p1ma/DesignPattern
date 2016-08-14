#ifndef PATTERN
#define PATTERN

#include <string>
#include <iostream>
#include <sstream>

#define PATTERN_NAME "@NAME = "
#define PATTERN_NAME_LENGTH 8
#define PATTERN_UML "@UML = "
#define PATTERN_UML_LENGTH 7
#define PATTERN_RESUME "@RESUME_FROM = "
#define PATTERN_RESUME_LENGTH 15
#define PATTERN_DESCRIPTION "@DESCRIPTION = "
#define PATTERN_DESCRIPTION_LENGTH 15

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
  std::string const getName(); // return pattern's name
  std::string const getImageName() ; // return image's name
  std::string const getURL();
  std::string const getDescription(); // return Pattern's description

};

#endif // PATTERN
