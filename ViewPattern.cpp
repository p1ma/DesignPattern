#include "ViewPattern.hpp"

ViewPattern::ViewPattern(GraphicModel *pModel) : View(pModel)
{
    this->setFixedSize((int)(GraphicModel::WIDTH),(int)(GraphicModel::HEIGHT / 2));

    // vertical layout
    this->verticalLayout = new QVBoxLayout();
    this->verticalLayout->setContentsMargins(10, 10, 10, 10);

    // image
    this->image = new QLabel("TEST");

    // add the label to the layout
    this->verticalLayout->addWidget(this->image);
    this->setLayout(this->verticalLayout);
}

ViewPattern::~ViewPattern(){
}

void ViewPattern::refresh() const{

}
