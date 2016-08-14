#ifndef VIEW_HPP
#define VIEW_HPP

#include "QWidget"

class View : public QWidget
{
public:
    View();
    ~View();
    virtual void refresh() const=0;
};

#endif // VIEW_HPP
