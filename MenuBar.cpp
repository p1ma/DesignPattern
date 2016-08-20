#include "MenuBar.hpp"

MenuBar::MenuBar(Model *model, QMainWindow *window) : QMenuBar(0), pModel(model), pWindow(window)
{
    this->addMenu(new QMenu("test"));
}

MenuBar::~MenuBar(){

}
