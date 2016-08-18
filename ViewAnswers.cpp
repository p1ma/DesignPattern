#include "ViewAnswers.hpp"

ViewAnswers::ViewAnswers(GraphicModel *pModel) : View(pModel)
{
    this->setFixedSize((int)(GraphicModel::WIDTH),(int)(GraphicModel::HEIGHT / 2));

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
    this->horizontalLayout_3 = new QHBoxLayout();
    this->horizontalLayout_3->setAlignment(this->verticalLayout,Qt::AlignCenter);
    this->horizontalLayout_3->setContentsMargins(25, 25, 25, 25);


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
    this->confirm = new QPushButton("Confirm", this);
    this->horizontalLayout_3->addWidget(this->confirm);

    // Connect button signal to appropriate slot
    connect(this->confirm, SIGNAL (clicked()), this, SLOT (confirmClick()));

    // ADD ELEMENTS
    this->verticalLayout->addLayout(this->horizontalLayout_1);
    this->verticalLayout->addLayout(this->horizontalLayout_2);
    this->verticalLayout->addLayout(this->horizontalLayout_3);

    // SET LAYOUT
    this->setLayout(this->verticalLayout);

    srand(std::time(0));
}

ViewAnswers::~ViewAnswers(){
    delete this->verticalLayout;
    delete this->answer1;
    delete this->answer2;
    delete this->answer3;
    delete this->answer4;
    delete this->horizontalLayout_1;
    delete this->horizontalLayout_2;
    delete this->horizontalLayout_3;
    delete this->confirm;
}

void ViewAnswers::refresh() const{

}

// set RadioButton's content
void ViewAnswers::setAnswers(std::vector<std::string> answers){
    // need to ramdom using built-in random generator:
    std::random_shuffle (answers.begin(), answers.end());
    if(answers.size() == 4){
            this->answer1->setText(QString::fromStdString(answers[0]));
            this->answer2->setText(QString::fromStdString(answers[1]));
            this->answer3->setText(QString::fromStdString(answers[2]));
            this->answer4->setText(QString::fromStdString(answers[3]));
    }
}

void ViewAnswers::confirmClick(){
    // radioButton group would be easier
    if(this->answer1->isChecked()){
        pGraphicModel->handle(this->answer1->text().toStdString());
    }
    if(this->answer2->isChecked()){
        pGraphicModel->handle(this->answer2->text().toStdString());
    }
    if(this->answer3->isChecked()){
        pGraphicModel->handle(this->answer3->text().toStdString());
    }
    if(this->answer4->isChecked()){
        pGraphicModel->handle(this->answer4->text().toStdString());
    }
}
