#ifndef VIEW_HPP
#define VIEW_HPP

#include "QWidget"
#include <QColor>
#include <QPalette>

class GraphicModel;

class View : public QWidget
{
protected :
    GraphicModel *pGraphicModel;
    QPalette Pal;
public:
    View(GraphicModel *pModel);
    virtual void refresh() const=0;
    GraphicModel *getModel();
    void setColor(QColor color);
};

#endif // VIEW_HPP
