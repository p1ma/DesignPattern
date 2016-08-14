#include "GraphicModel.hpp"

GraphicModel::GraphicModel()
{
    this->window = new MyWindow();
    this->window->setWindowTitle(QString::fromUtf8("Pattern Quiz") );
    this->window->show();
}

GraphicModel::~GraphicModel(){
    delete window;
}
