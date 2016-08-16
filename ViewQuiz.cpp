#include "ViewQuiz.hpp"
#include "ViewAnswers.hpp"
#include "ViewPattern.hpp"

ViewQuiz::ViewQuiz(GraphicModel *pModel) : View(pModel){
    pAnswer = new ViewAnswers(pModel);
    pPattern = new ViewPattern(pModel);

    this->setFixedSize(GraphicModel::WIDTH,GraphicModel::HEIGHT);

    // vertical layout
    this->pVerticalLayout = new QVBoxLayout();
    this->pVerticalLayout->setAlignment(Qt::AlignCenter);
    this->pVerticalLayout->setContentsMargins(5, 5, 5, 5);
    this->pVerticalLayout->addWidget(pPattern);
    this->pVerticalLayout->addWidget(pAnswer);
    this->setLayout(this->pVerticalLayout);
}

ViewQuiz::~ViewQuiz(){
    delete this->pAnswer;
    delete this->pPattern;
}

void ViewQuiz::refresh() const{
    pAnswer->refresh();
    pPattern->refresh();
}


void ViewQuiz::setQuestion(QPixmap *image, std::vector<std::string> answers){
    this->pAnswer->setAnswers(answers);
    this->pPattern->setImage(image);
}
