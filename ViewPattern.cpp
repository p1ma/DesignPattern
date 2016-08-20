#include "ViewPattern.hpp"

ViewPattern::ViewPattern(GraphicModel *pModel) : View(pModel)
{
    this->setFixedSize((int)(GraphicModel::WIDTH),(int)(GraphicModel::HEIGHT / 2));

    // vertical layout
    this->verticalLayout = new QVBoxLayout();
    this->verticalLayout->setContentsMargins(10, 10, 10, 10);

    // image
    this->image = new QLabel("");
    this->image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // add the label to the layout
    this->verticalLayout->addWidget(this->image, Qt::AlignCenter);
    this->setLayout(this->verticalLayout);

}

ViewPattern::~ViewPattern(){
    delete this->image;
    delete this->verticalLayout;
}

void ViewPattern::refresh() const{

}

void ViewPattern::setImage(QPixmap *image){
    this->image->setPixmap(*image);
}
