#include "View.hpp"

View::View(GraphicModel *pModel) : QWidget(), pGraphicModel(pModel)
{
}

View::~View(){
}

// return graphicModel
GraphicModel *View::getModel(){
    return this->pGraphicModel;
}
