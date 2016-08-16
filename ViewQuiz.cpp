#include "ViewQuiz.hpp"
#include "ViewAnswers.hpp"
#include "ViewPattern.hpp"

ViewQuiz::ViewQuiz(GraphicModel *pModel) : View(pModel){
    pAnswer = new ViewAnswers(pModel);
    pPattern = new ViewPattern(pModel);

    this->setFixedSize(GraphicModel::WIDTH,GraphicModel::HEIGHT);

    // vertical layout
    this->pVerticalLayout = new QVBoxLayout();
    this->pVerticalLayout->setContentsMargins(5, 5, 5, 5);
    this->pVerticalLayout->addWidget(pPattern);
    this->pVerticalLayout->addWidget(pAnswer);
    this->setLayout(this->pVerticalLayout);
}

void ViewQuiz::refresh() const{
    pAnswer->refresh();
    pPattern->refresh();
}
