#include "FileReader.hpp"

// constructor
FileReader::FileReader(){
  this->pFile = new std::ifstream();
  this->directory = new char[LENGTH];
  this->imageDirectory = new char[LENGTH];
  getcwd(directory, (size_t)(LENGTH - 1));
  getcwd(imageDirectory, (size_t)(LENGTH - 1));
  strcat(directory, "/patterns/informations/");
  strcat(imageDirectory, "/patterns/images/");
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
  if(size > (pattern.size() + 1)){
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

// returns files names find in 'directory'
std::vector<std::string> const FileReader::getFiles(){
    std::vector<std::string> vector;
    std::string pattern = ".pattern";
    std::string example = "example.pattern" ; // to include this file
    unsigned int length = pattern.size();
    std::string file = "";
    DIR *dir;
    // open the directory
    dir = opendir(this->directory);
    if(dir != NULL){
        struct dirent *direct = NULL;
        // parse the files in it
        while((direct = readdir(dir)) != NULL){
            file = direct->d_name;
            if(file.size() > (length + 1)){
                // file ends with '.pattern'
                if((file.compare((file.size() - length), length, pattern) == 0)
                        && (file.compare(example) != 0)){
                    vector.push_back(file);
                }
            }
        }
        closedir(dir);
        return vector;
    }else{
        return vector; // empty vector
    }
}

// return QPixmap containing the pattern's image
QPixmap *FileReader::getImage(const char *link){
    QString path = "patterns/images/";
    path.append(link);
    QFile file(path);
    if(file.exists()){
        std::cout << "FILE OK" << std::endl;
    }
    QPixmap *pImage = new QPixmap();
    std::cout << path.toStdString() << std::endl;
    path = "/home/pima/Documents/Training/CPP/DesignPattern/patterns/images/factory.png"; // OK directly
    pImage->load(path);
    return pImage;
}
