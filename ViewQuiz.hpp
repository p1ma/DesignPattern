#ifndef VIEWQUIZ_HPP
#define VIEWQUIZ_HPP

#include "View.hpp"
class ViewAnswers;
class ViewPattern;
#include "GraphicModel.hpp"
#include <QPixmap>
#include <QVBoxLayout>

class ViewQuiz : public View
{
    Q_OBJECT
private :
    ViewAnswers *pAnswer;
    ViewPattern *pPattern;
    QVBoxLayout *pVerticalLayout;
public:
    ViewQuiz(GraphicModel *pModel);
    ~ViewQuiz();
    virtual void refresh() const;
    void setQuestion(QPixmap &image, std::vector<std::string> answers);
};

#endif // VIEWQUIZ_HPP
