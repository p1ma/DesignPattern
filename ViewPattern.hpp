#ifndef VIEWPATTERN_HPP
#define VIEWPATTERN_HPP

#include "View.hpp"
#include <QLabel>
#include <QVBoxLayout>

class ViewPattern : public View
{
    Q_OBJECT
public:
    ViewPattern();
    ~ViewPattern();
    virtual void refresh() const;
private :
    QVBoxLayout *verticalLayout;
    QLabel *image;
};

#endif // VIEWPATTERN_HPP