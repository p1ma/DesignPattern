#ifndef VIEWANSWERS_HPP
#define VIEWANSWERS_HPP

#include "View.hpp"
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class ViewAnswers : public View
{
private :
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *answer1, *answer2, *answer3, *answer4;
    QPushButton *confirm;
public:
    ViewAnswers();
    ~ViewAnswers();
    virtual void refresh() const;
};

#endif // VIEWANSWERS_HPP
