#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <dirent.h>

#define LENGTH 512

class FileReader {

private :
  std::ifstream *pFile;
  char *directory;
  inline bool exist(const std::string& name);
  std::string read(const std::string& name);
public :
  FileReader(); // constructor
  ~FileReader(); // destructor
  std::string readFile(const std::string& name); // check existence / pName's size before calling method read()
  std::vector<std::string> const getFiles(); // returns files names find in 'directory'
};

#endif // FILE_READER
