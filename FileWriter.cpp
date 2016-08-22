#include "FileWriter.hpp"

// constructor
FileWriter::FileWriter(char *pathInformationsDirectory, char *pathImageDirectory) : directory(pathInformationsDirectory), imageDirectory(pathImageDirectory)
{
}

// destructor
FileWriter::~FileWriter(){

}

// write 2 new files, one with the pattern's information (name, description, ulr) and image (.png)
void FileWriter::write(std::string name, std::string url, std::string description, std::string image){
   std::locale loc;
   std::string formatedName = name,fileName = name;
   std::cout << "NAME : " << name << std::endl;
   // LOWER ALL CHARATECTERS FOR FILENAME
   std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
   std::string::iterator it=formatedName.begin();
   it++;
   // LOWER ALL CHARATECTERS FOR FILENAME EXCEPT FIRST ONE
   std::transform(formatedName.begin(), it, formatedName.begin(), ::toupper);
   std::transform(it, formatedName.end(), formatedName.begin() + 1, ::tolower);
   std::string pattern = fileName + ".pattern";
   char *path = this->directory;
   strcat(path,pattern.c_str());

   // OPEN FILE TO WRITE INFOS
   std::ofstream file;
   file.open(path, std::ofstream::out | std::ofstream::app);

   // if the file is open, then i can write the infos inside
   if (file.is_open()){
       file << "@NAME = " << formatedName << std::endl;
       file << "@UML = " << pattern << std::endl;
       file << "@RESUME_FROM = " << url << std::endl;
       file << "@DESCRIPTION = " << description << std::endl;
   }
   std::cout << "file " << path << " over" << std::endl;
   file.close();

   // read the .png image using 'image' path
   std::ifstream read;
   read.open(image.c_str(), std::ifstream::in | std::ifstream::binary);
   char *buffer;
   int size = 0;
   if(read.is_open()){
       // get length of file:
           read.seekg (0, read.end);
           size = read.tellg();
           read.seekg (0, read.beg);

           buffer = new char[size];

           //read the file and put data into buffer
           read.read(buffer,size);
   }
   read.close();

   // write the .png image now
   path = this->imageDirectory;
   pattern = fileName + ".png";
   strcat(path,pattern.c_str());
   file.open(path, std::ofstream::out | std::ofstream::app | std::ofstream::binary);
   if(file.is_open()){
        file.write(buffer,size);
   }
   file.close();
}
