#ifndef VIEWANSWERS_HPP
#define VIEWANSWERS_HPP

#include "View.hpp"
#include "GraphicModel.hpp"
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <ctime>
#include <vector>

class GraphicModel;

class ViewAnswers : public View
{
    Q_OBJECT
private :
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *answer1, *answer2, *answer3, *answer4;
    QPushButton *confirm;
    QString style;
private slots:
    void confirmClick();
public:
    ViewAnswers(GraphicModel *pModel);
    ~ViewAnswers();
    virtual void refresh() const;
    void setAnswers(std::vector<std::string> answers);
};

#endif // VIEWANSWERS_HPP
