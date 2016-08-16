#ifndef VIEWQUIZ_HPP
#define VIEWQUIZ_HPP

#include "View.hpp"
class ViewAnswers;
class ViewPattern;
#include "GraphicModel.hpp"
#include <QVBoxLayout>

class ViewQuiz : public View
{
private :
    ViewAnswers *pAnswer;
    ViewPattern *pPattern;
    QVBoxLayout *pVerticalLayout;
public:
    ViewQuiz(GraphicModel *pModel);
    virtual void refresh() const;
};

#endif // VIEWQUIZ_HPP
