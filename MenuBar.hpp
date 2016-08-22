#ifndef MENUBAR_HPP
#define MENUBAR_HPP

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include "GraphicModel.hpp"
#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QDir>
#include <iostream>

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
    QLineEdit *name;
    QLineEdit *url;
    QLineEdit *image;
    QTextEdit *description;
public:
    MenuBar(GraphicModel* const model);
    ~MenuBar();
private slots:
    void exitWindow();
    void addNewPattern();
    void chooseFile();
    void accept();
    void reject();
};

#endif // MENUBAR_HPP
