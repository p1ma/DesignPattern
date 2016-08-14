#include "ViewAnswers.hpp"

ViewAnswers::ViewAnswers() : View()
{
    this->setFixedSize(500,250);

    // VERTICAL LAYOUT
    this->verticalLayout = new QVBoxLayout();
    this->verticalLayout->setContentsMargins(5, 5, 5, 5);

    // HORIZONTAL LAYOUT
    this->horizontalLayout_1 = new QHBoxLayout();
    this->horizontalLayout_1->setContentsMargins(5, 5, 5, 5);
    this->horizontalLayout_1->setAlignment(this->verticalLayout,Qt::AlignCenter);
    this->horizontalLayout_2 = new QHBoxLayout();
    this->horizontalLayout_2->setAlignment(this->verticalLayout,Qt::AlignCenter);
    this->horizontalLayout_2->setContentsMargins(5, 5, 5, 5);

    // FILL HORIZONTALS LAYOUTS - test
    this->answer1 = new QRadioButton("Answer ");
    this->answer2 = new QRadioButton("Answer ");
    this->answer3 = new QRadioButton("Answer ");
    this->answer4 = new QRadioButton("Answer ");

    this->horizontalLayout_1->addWidget(this->answer1);
    this->horizontalLayout_1->addWidget(this->answer2);
    this->horizontalLayout_2->addWidget(this->answer3);
    this->horizontalLayout_2->addWidget(this->answer4);

    // CONFIRM BUTTON
    this->confirm = new QPushButton("Confirm");

    // ADD ELEMENTS
    this->verticalLayout->addLayout(this->horizontalLayout_1);
    this->verticalLayout->addLayout(this->horizontalLayout_2);
    this->verticalLayout->addWidget(this->confirm);

    // SET LAYOUT
    this->setLayout(this->verticalLayout);
}

ViewAnswers::~ViewAnswers(){

}

void ViewAnswers::refresh() const{

}
