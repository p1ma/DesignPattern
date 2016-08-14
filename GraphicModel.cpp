#include "GraphicModel.hpp"

GraphicModel::GraphicModel() : QObject()
{
    this->window = new MyWindow();
    this->window->setFixedSize(1024,768);
    this->window->setWindowTitle(QString::fromUtf8("Pattern Quiz") );
    this->window->show();
}

GraphicModel::~GraphicModel(){
    delete this->window;
}

// change current view
void GraphicModel::setView(View *v){
    this->window->setCentralWidget(v);
    this->window->show();
}
