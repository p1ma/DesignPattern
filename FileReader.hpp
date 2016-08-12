#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <fstream>

class FileReader {

private :
  std::ifstream *pFile;
  std::string directory;
  inline bool exist(const std::string& name);
  std::string read(const std::string& name);
public :
  FileReader(); // constructor
  ~FileReader(); // destructor
  std::string readFile(const std::string& name); // check existence / pName's size before calling method read()

};

#endif // FILE_READER
