#ifndef FILEWRITER_HPP
#define FILEWRITER_HPP

#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>
#include <algorithm>

class FileWriter
{
private :
    char *directory;
    char *imageDirectory;
public:
    FileWriter(char *pathInformationsDirectory, char *pathImageDirectory);
    ~FileWriter();
    void write(std::string name, std::string url, std::string description, std::string image);
};

#endif // FILEWRITER_HPP
