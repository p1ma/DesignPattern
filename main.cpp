#include <iostream>
#include "FileReader.hpp"
#include "Pattern.hpp"
#include "MainWindow.hpp"
#include <QApplication>

using namespace std;

FileReader *pFileReader;
Pattern *pPattern;

int main(int argc, char* argv[]){
  QApplication a(argc,argv);
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

  // TEST GETFILES()
  std::vector<std::string> files;
  files = pFileReader->getFiles();
  if(files.size() > 0){
      cout << "Size greater than 0 : OK" << endl;
      for(unsigned int i = 0 ; i < files.size() ; i++){
          cout << "File num ." << i << endl;
          cout << files[i] << endl << "----" << endl;
      }
  }

  // TEST CONSTRUCTOR PATTERN
  cout << "TEST CONSTRUCTOR PATTERN" << endl;
  string param =  pFileReader->readFile(pattern);
  pPattern = new Pattern(param);
  cout << pPattern->getInformations() << endl;
  cout << pPattern->getName() << endl;
  cout << pPattern->getImageName() << endl;
  cout << pPattern->getURL() << endl;
  cout << pPattern->getDescription() << endl;
  //END TEST PATTERN


  // delete FileReader ptr
  delete pFileReader;
  delete pPattern;
  return a.exec();
}
