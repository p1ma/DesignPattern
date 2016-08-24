#ifndef VIEWINFORMATION_HPP
#define VIEWINFORMATION_HPP

#include "View.hpp"
#include "GraphicModel.hpp"
#include <QLabel>
#include <QVBoxLayout>

class ViewInformation : public View
{
    Q_OBJECT
private :
    QVBoxLayout *verticalLayout;
    QLabel *patterName;
    QLabel *patternImage;
    QLabel *descriptionTitle;
    QLabel *patternDescription;

public:
    ViewInformation(GraphicModel *pModel);
    ~ViewInformation();
    virtual void refresh() const;
    void set(std::string const name, QPixmap *image, std::string const description, std::string const url);
};

#endif // VIEWINFORMATION_HPP
