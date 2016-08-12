#include "FileReader.hpp"

// constructor
FileReader::FileReader(){
  this->pFile = new std::ifstream();
  this->directory = new char[LENGTH];
  getcwd(directory, (size_t)(LENGTH - 1));
  strcat(directory, "/patterns/informations/");
}

// destructor
FileReader::~FileReader(){
  delete this->pFile; // delete file pointer
  delete this->directory;
}

// check name's properties
std::string FileReader::readFile(const std::string& name){
  std::string suffix;
  std::string pattern = ".pattern";
  unsigned int size = name.size();
  if(size > pattern.size()){
    if(name.compare((size - 8), 8,pattern) == 0){
      std::string file = directory;
      file += name;
      if(exist(file)){
	return FileReader::read(file);
      }else{
	return "(readFile) FILE DOES NOT EXIST";
      }
    }else{
      return "(readFile) FILE .PATTERN ONLY";
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
    return true;
  }
  return false;
}

// read
std::string FileReader::read(const std::string& name){
  std::string res = "";
  const char *file = name.c_str();
  this->pFile->open(file, std::ifstream::in);

  //length of file
  pFile->seekg(0,pFile->end);
  int length = pFile->tellg();
  pFile->seekg(0,pFile->beg);
  // reading...
  char *buffer = new char[length];
  pFile->read(buffer,length);
  this->pFile->close();
  res = buffer;
  return res;
}


