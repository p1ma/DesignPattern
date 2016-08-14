#include "GraphicModel.hpp"

GraphicModel::GraphicModel(Model *model) : QObject(), pModel(model)
{
    this->window = new MyWindow();
    this->window->setFixedSize(1024,768);
    this->window->setWindowTitle(QString::fromUtf8("Pattern Quiz") );
    this->window->show();

    // instanciate views
    ViewAnswers *answers = new ViewAnswers(this);
    ViewPattern *pattern = new ViewPattern(this);
    views.push_back(answers);
    views.push_back(pattern);
}

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
