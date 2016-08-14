#include <iostream>
#include "Model.hpp"
#include <QApplication>
#include <QLabel>

using namespace std;

Model *pModel;

int main(int argc, char* argv[]){
  QApplication a(argc,argv);
  pModel = new Model(); // Model instanciation
  cout << "TEST GET PATTERNS VIA MODEL CLASS" << endl;
  cout << pModel->getPatterns() << endl;
  cout << "END TEST GET PATTERNS VIA MODEL CLASS" << endl;

  // PLAY
  pModel->play();

  // TEST READFILE()
  /*
   * cout << "TEST READFILE" << endl;
  string pattern = "";
  cout << pFileReader->readFile(pattern) << endl; // INVALID NAME
  pattern = "RANDOMFILE";
  cout << pFileReader->readFile(pattern) << endl; // FILE .PATTERN ONLY
  pattern += ".pattern";
  cout << pFileReader->readFile(pattern) << endl; // FILE DOES NOT EXIST
  pattern = "factory.pattern";
  cout << pFileReader->readFile(pattern) << endl; // OK, FILE CORRECT
  */
  // END TEST READFILE()

  // TEST GETFILES()
 /* std::vector<std::string> files;
  files = pFileReader->getFiles();
  if(files.size() > 0){
      cout << "Size greater than 0 : OK" << endl;
      for(unsigned int i = 0 ; i < files.size() ; i++){
          cout << "File num ." << i << endl;
          cout << files[i] << endl << "----" << endl;
      }
  }*/

  // TEST CONSTRUCTOR PATTERN
  /*cout << "TEST CONSTRUCTOR PATTERN" << endl;
  string param =  pFileReader->readFile(pattern);
  pPattern = new Pattern(param);
  cout << pPattern->getInformations() << endl;
  cout << pPattern->getName() << endl;
  cout << pPattern->getImageName() << endl;
  cout << pPattern->getURL() << endl;
  cout << pPattern->getDescription() << endl;*/
  //END TEST PATTERN

  // TEST PRINT IMAGE AND INFOS
  /*string image = pPattern->getImageName();
  cout << "image load : " << image << endl;
  QPixmap pixmap= pFileReader->getImage(image.c_str()) ;
  QLabel img;
  img.setPixmap(pixmap);
  img.show();
  cout << pixmap.depth() << "," << pixmap.height() << endl;*/

  // exec
  return a.exec();
}
