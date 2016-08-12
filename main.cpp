#include <iostream>
#include "FileReader.hpp"

using namespace std;

FileReader *pFileReader;

int main(int argc, char* argv[]){
  pFileReader = new FileReader();
  std::string pattern = "";
  cout << pFileReader->readFile(pattern) << endl; // INVALID NAME
  pattern += "RANDOM";
  cout << pFileReader->readFile(pattern) << endl; // .PNG ONLY OK
  pattern += ".png";
  cout << pFileReader->readFile(pattern) << endl; // FILE DOES NOT EXIST
  pattern = "factory.png";
  cout << pFileReader->readFile(pattern) << endl;
  // delete ptr
  delete pFileReader;
  return 1;
}
