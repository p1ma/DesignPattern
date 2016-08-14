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
void GraphicModel::play(std::vector<Pattern *> const pPatterns){
    // if there is at least 1 pattern in the directory /patterns/informations/
    if(pPatterns.size() > 0){

    }else{
        std::cout << "Quiz not available." << std::endl
                     << "Please add patterns informations in /patterns/informations/" << std::endl
                        <<"And image (.png) in /patterns/images/" << std::endl;
        close();
    }
}

// close all
void GraphicModel::close(){
    time_t begin,end;
    time(&begin);
    time(&end);
    end += 3;
    // wait 3s
    while(begin < end){
        time(&begin);
    }
    this->window->close();
    delete this->pModel;
    return;
}
