#include <iostream>
#include "FileReader.hpp"

using namespace std;

FileReader *pFileReader;

int main(int argc, char* argv[]){
  pFileReader = new FileReader();

  // TEST READFILE()
  std::string pattern = "";
  cout << pFileReader->readFile(pattern) << endl; // INVALID NAME
  pattern += "RANDOM";
  cout << pFileReader->readFile(pattern) << endl; // .PATTERN ONLY OK
  pattern += ".pattern";
  cout << pFileReader->readFile(pattern) << endl; // FILE DOES NOT EXIST
  pattern = "factory.pattern";
  cout << pFileReader->readFile(pattern) << endl; // OK, FILE CORRECT
  // END TEST READFILE()

  // delete FileReader ptr
  delete pFileReader;
  return 1;
}
