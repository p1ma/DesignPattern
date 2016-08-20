#include "View.hpp"

View::View(GraphicModel *pModel) : QWidget(), pGraphicModel(pModel)
{
}
// return graphicModel
GraphicModel *View::getModel(){
    return this->pGraphicModel;
}

// set background color
void View::setColor(QColor color){
    Pal.setColor(QPalette::Background, color);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();
}
