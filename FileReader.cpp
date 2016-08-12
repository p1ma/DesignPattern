#include "FileReader.hpp"

// constructor
FileReader::FileReader(){
  this->pFile = new std::ifstream();
  this->directory = "/patterns/images/";
}

// destructor
FileReader::~FileReader(){
  delete this->pFile; // delete file pointer
}

// check name's properties
std::string FileReader::readFile(const std::string& name){
  std::string suffix;
  std::string png = "png";
  int size = name.size();
  if(size != 0){
    if(name.compare((size - 3), 3,png) == 0){
      std::string file = directory;
      file += name.c_str();
      if(exist(file)){
	return FileReader::read(file);
      }else{
	return "(readFile) FILE DOES NOT EXIST";
      }
    }else{
      return "(readFile) FILE .PNG ONLY";
    }
  }else{
    return "(readFile) INVALID NAME";
  }
}

// check file 'name' existence
inline bool FileReader::exist(const std::string& name){
  FILE *exist;
  if((exist = fopen(name.c_str(), "r"))){
    fclose(exist);
    delete exist;
    return true;
  }
  return false;
}

// read
std::string FileReader::read(const std::string& name){
  return "OK";
}


