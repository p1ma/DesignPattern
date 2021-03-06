#include "Pattern.hpp"

// constructor
Pattern::Pattern(std::string const param){
  bool ok = ((param.find(PATTERN_NAME) != std::string::npos)
    && (param.find(PATTERN_UML) != std::string::npos)
    && (param.find(PATTERN_RESUME) != std::string::npos)
    && (param.find(PATTERN_DESCRIPTION) != std::string::npos));

  if(ok){
    std::size_t line_name, line_uml, line_resume, line_description;
    line_name = (param.find(PATTERN_NAME));
    line_uml = (param.find(PATTERN_UML));
    line_resume = (param.find(PATTERN_RESUME));
    line_description =(param.find(PATTERN_DESCRIPTION));
    this->name = param.substr(line_name, (line_uml - line_name));
    this->image_name = param.substr(line_uml, (line_resume - line_uml));
    this->url_informations = param.substr(line_resume, (line_description - line_resume));
    this->description = param.substr(line_description); 
  }
}

Pattern::Pattern(std::string nameP, std::string img,  std::string url, std::string descriptionP){
    this->name = nameP;
    this->image_name = img;
    this->url_informations = url;
    this->description = descriptionP;
}

// destructor
Pattern::~Pattern(){
}

// returns pattern's informations
std::string const Pattern::getInformations(){
 std::stringstream res;
 // TODO
 res << "Pattern name : " << this->name  
     << "Image name : " << this->image_name 
     << "Url informations : " << this->url_informations 
     << "Description : " << this->description << std::endl;
 return res.str();
}

// return pattern's name
std::string const Pattern::getName(){
    return (this->name.substr(PATTERN_NAME_LENGTH));
}

// return image's name
std::string const Pattern::getImageName(){
    return (this->image_name.substr(PATTERN_UML_LENGTH));
}


std::string const Pattern::getURL(){
    return (this->url_informations.substr(PATTERN_RESUME_LENGTH));
}

// return Pattern's description
std::string const Pattern::getDescription(){
    return (this->description.substr(PATTERN_DESCRIPTION_LENGTH));
}
