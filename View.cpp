#include "View.hpp"

View::View(GraphicModel *pModel) : QWidget(), pGraphicModel(pModel)
{
}
// return graphicModel
GraphicModel *View::getModel(){
    return this->pGraphicModel;
}
