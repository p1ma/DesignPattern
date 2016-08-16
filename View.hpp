#ifndef VIEW_HPP
#define VIEW_HPP

#include "QWidget"

class GraphicModel;

class View : public QWidget
{
protected :
    GraphicModel *pGraphicModel;
public:
    View(GraphicModel *pModel);
    virtual void refresh() const=0;
    GraphicModel *getModel();
};

#endif // VIEW_HPP
