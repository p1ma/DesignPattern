#ifndef VIEWSTART_HPP
#define VIEWSTART_HPP
#include "View.hpp"
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>

class GraphicModel;
/*
 * 1rst View
 */
class ViewStart : public View
{
private :
    QVBoxLayout *pVerticalLayout;
    QLabel *title;
    QLabel *info;
    QLabel *quiz;
public:
    ViewStart(GraphicModel *pModel);
    ~ViewStart();
    virtual void refresh() const;
};

#endif // VIEWSTART_HPP
