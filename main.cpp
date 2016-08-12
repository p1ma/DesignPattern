#include <iostream>
#include "FileReader.hpp"
#include "Pattern.hpp"

using namespace std;

FileReader *pFileReader;
Pattern *pPattern;

int main(int argc, char* argv[]){
  pFileReader = new FileReader();

  // TEST READFILE()
  cout << "TEST READFILE" << endl;
  string pattern = "";
  cout << pFileReader->readFile(pattern) << endl; // INVALID NAME
  pattern = "RANDOMFILE";
  cout << pFileReader->readFile(pattern) << endl; // FILE .PATTERN ONLY
  pattern += ".pattern";
  cout << pFileReader->readFile(pattern) << endl; // FILE DOES NOT EXIST
  pattern = "factory.pattern";
  cout << pFileReader->readFile(pattern) << endl; // OK, FILE CORRECT
  // END TEST READFILE()

  // TEST CONSTRUCTOR PATTERN
  cout << "TEST CONSTRUCTOR PATTERN" << endl;
  string param =  pFileReader->readFile(pattern);
  pPattern = new Pattern(param);
  cout << pPattern->getInformations() << endl;
  // delete FileReader ptr
  delete pFileReader;
  delete pPattern;
  return 1;
}
