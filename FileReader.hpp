#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <dirent.h>
#include <QPixmap>
#include <QCoreApplication>
#include <QFile>
#include <QDir>

#define LENGTH 512

class FileReader {

private :
  std::ifstream *pFile;
  char *directory;
  char *imageDirectory;
  inline bool exist(const std::string& name);
  std::string read(const std::string& name);
  inline bool compare(std::string s1, std::string s2);
public :
  FileReader(); // constructor
  ~FileReader(); // destructor
  std::string readFile(const std::string& name); // check existence and name's size before calling method read()
  std::vector<std::string> const getFiles(); // returns files names find in 'directory'
  QPixmap *getImage(std::string link); // return QPixmap containing the pattern's image
  char *getDirectory(); // return directory
  char *getImageDirectory(); // return imageDirectory
};

#endif // FILE_READER
