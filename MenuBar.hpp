#ifndef MENUBAR_HPP
#define MENUBAR_HPP

#include <QMenuBar>

class Model;
class QMainWindow;

class MenuBar : public QMenuBar
{
private :
    Model *pModel;
    QMainWindow *pWindow;
public:
    MenuBar(Model *model, QMainWindow *window);
    ~MenuBar();
};

#endif // MENUBAR_HPP
