#ifndef MENUBAR_HPP
#define MENUBAR_HPP

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include "GraphicModel.hpp"
#include <QInputDialog>

class MenuBar : public QMenuBar
{
    Q_OBJECT
private :
    GraphicModel* const pGraphicModel;
    QMenu *file;
    QMenu *patternInfos;
    QAction *exit;
    QAction *addPattern;
    QAction *informations;
    QActionGroup *groupFile;
public:
    MenuBar(GraphicModel* const model);
    ~MenuBar();
private slots:
    void exitWindow();
    void addNewPattern();
};

#endif // MENUBAR_HPP
