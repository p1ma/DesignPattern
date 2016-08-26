#include "ViewStart.hpp"
#include "GraphicModel.hpp"

ViewStart::ViewStart(GraphicModel *pModel) : View(pModel)
{
    this->setFixedSize(GraphicModel::WIDTH,GraphicModel::HEIGHT);

    // LAYOUT
    this->pVerticalLayout = new QVBoxLayout();
    this->pVerticalLayout->setAlignment(Qt::AlignCenter);
    this->pVerticalLayout->setContentsMargins(5, 5, 5, 5);
    this->pVerticalLayout->setSpacing(0);

    // QLABEL
    this->title = new QLabel("WELCOME");
    this->title->setAlignment(Qt::AlignCenter);
    // font
    QFont font;
    font.setPointSize(16);
    font.setBold(true);
    font.setUnderline(true);
    this->title->setFont(font);

    this->info = new QLabel();
    this->info->setText("\t-To learn about the design pattern available : Menu -> Pattern -> Informations \n");
    font.setPointSize(12);
    font.setBold(false);
    font.setUnderline(false);
    this->info->setAlignment(Qt::AlignLeft);

    this->quiz = new QLabel();
    this->quiz->setText("\t-To start the quiz : Menu -> Quiz -> Start Quiz \n");
    font.setPointSize(12);
    font.setBold(false);
    font.setUnderline(false);
    this->quiz->setAlignment(Qt::AlignLeft);

    // add the widgets
    this->pVerticalLayout->addWidget(this->title,Qt::AlignHCenter || Qt::AlignVCenter);
    this->pVerticalLayout->addWidget(this->info,Qt::AlignLeft || Qt::AlignTop);
    this->pVerticalLayout->addWidget(this->quiz,Qt::AlignLeft || Qt::AlignTop);
    this->setLayout(pVerticalLayout);
}

ViewStart::~ViewStart(){
    delete pVerticalLayout;
}


void ViewStart::refresh() const{

}
