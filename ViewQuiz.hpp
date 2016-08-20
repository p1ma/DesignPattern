#ifndef VIEWQUIZ_HPP
#define VIEWQUIZ_HPP

#include "View.hpp"
#include "Pattern.hpp"
#include <QPixmap>
#include <QVBoxLayout>

class ViewAnswers;
class ViewPattern;
class GraphicModel;

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
    void setQuestion(QPixmap *image, std::vector<std::string> answers);
    void setViewsColor(QColor color); // set ViewAnswer and ViewPattern background color
};

#endif // VIEWQUIZ_HPP
