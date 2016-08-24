#include "Model.hpp"

//constructor
Model::Model()
{
    this->pFileReader = new FileReader();
    this->pFileWriter = new FileWriter(pFileReader->getDirectory(), pFileReader->getImageDirectory());
    fillVector();
    this->pGraphicModel = new GraphicModel(this);
}

// destructor
Model::~Model(){
    delete pGraphicModel;
    delete pFileReader;
    delete pFileWriter;
}

// fill the vector with all the patterns find in the directory patterns/informations/
void Model::fillVector(){
    std::vector<std::string> list;
    // get all files in /patterns/informations except example.pattern
    list = this->pFileReader->getFiles();

    // iterate
    std::string infos = "";
    Pattern *pPattern;
    for(unsigned int ind = 0 ; ind < list.size() ; ind++){
        infos = this->pFileReader->readFile(list[ind]);
        pPattern = new Pattern(infos);
        this->patterns.push_back(pPattern);
    }
}

// returns all patterns' informations in 'patterns'
std::string const Model::getPatterns()
{
    std::string res;
    for(unsigned int ind = 0 ; ind < this->patterns.size() ; ind++){
        res.append(this->patterns[ind]->getInformations());
    }
    return res;
}

//launch quiz
void Model::play(){
    //ask GraphicModel to play using all Model's informations
    this->pGraphicModel->play(this->patterns);
}

// return pattern 'name' image
QPixmap *Model::getImage(std::string const name){
    return this->pFileReader->getImage(name.c_str());
}

// add a new pattern
void Model::add(std::string name, std::string url, std::string description, std::string image){
    Pattern *p = this->pFileWriter->write(name,url,description,image);
    this->patterns.push_back(p);
    // program needs to be rebooted
}

// return patterns
std::vector<Pattern *> Model::getList(){
    return this->patterns;
}

// launch graphic interface
void Model::launch(){
    this->pGraphicModel->launch();
}
