#ifndef VIEWANSWERS_HPP
#define VIEWANSWERS_HPP

#include "View.hpp"
#include "GraphicModel.hpp"
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class GraphicModel;

class ViewAnswers : public View
{
    Q_OBJECT
private :
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *answer1, *answer2, *answer3, *answer4;
    QPushButton *confirm;
private slots:
    void confirmClick();
public:
    ViewAnswers(GraphicModel *pModel);
    ~ViewAnswers();
    virtual void refresh() const;
    void setAnswers(std::vector<std::string> answers);
};

#endif // VIEWANSWERS_HPP
