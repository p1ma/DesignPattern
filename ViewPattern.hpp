#ifndef VIEWPATTERN_HPP
#define VIEWPATTERN_HPP

#include "View.hpp"
#include "GraphicModel.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

class GraphicModel;

class ViewPattern : public View
{
    Q_OBJECT
public:
    ViewPattern(GraphicModel *pModel);
    ~ViewPattern();
    virtual void refresh() const;
    void setImage(QPixmap *image);
private :
    QVBoxLayout *verticalLayout;
    QLabel *image;
};

#endif // VIEWPATTERN_HPP
