#include "GraphicModel.hpp"

// constructor
GraphicModel::GraphicModel(Model *model) : QObject(), pModel(model)
{
    this->window = new MyWindow();
    this->window->setFixedSize(1024,768);
    this->window->setWindowTitle(QString::fromUtf8("Pattern Quiz") );
    //this->window->show();

    // instanciate views
    ViewAnswers *answers = new ViewAnswers(this);
    ViewPattern *pattern = new ViewPattern(this);
    views.push_back(answers);
    views.push_back(pattern);
}

// destructor
GraphicModel::~GraphicModel(){
    delete this->window;
}

// change current view
void GraphicModel::setView(View *v){
    this->window->setCentralWidget(v);
    this->window->show();
}

// refresh all views
void GraphicModel::refreshViews(){
    for(unsigned int i = 0 ; i < views.size() ; i++){
        views[i]->refresh();
    }
}

// ask MyWindow to show
void GraphicModel::show(){
    this->window->show();
}

// play graphic quiz
void GraphicModel::play(std::vector<Pattern *> patterns){
    // if there is at least 1 pattern in the directory /patterns/informations/
    if(pPatterns.size() > 4){
        copyToVector(patterns); // copy patterns vector to pPatterns
    }else{
        std::cout << "Quiz not available." << std::endl
                     << "Please add patterns informations in /patterns/informations/" << std::endl
                        <<"And image (.png) in /patterns/images/" << std::endl;
        close();
    }
}

// close all
void GraphicModel::close(){
    // need timer or smth
    this->window->close();
    //delete this->pModel;
    return;
}

 // 4 answers, 1 correct ,3 incorrects, return the 3 incorrects
std::vector<std::string> GraphicModel::getOthersAnswers(std::string const goodOne){
    std::vector<std::string> answers;

    return answers;
}

void GraphicModel::copyToVector(std::vector<Pattern *> patterns){
    this->pPatterns.swap(patterns); // error 14/08/2016 22h41
}
