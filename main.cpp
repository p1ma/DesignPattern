#include <iostream>
#include "FileReader.hpp"
#include "Pattern.hpp"

using namespace std;

FileReader *pFileReader;
Pattern *pPattern;

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

  // TEST CONSTRUCTOR PATTERN
  std::string param =  pFileReader->readFile(pattern);
  pPattern = new Pattern(param);
  // delete FileReader ptr
  delete pFileReader;
  delete pPattern;
  return 1;
}
