#ifndef GRAPHICMODEL_HPP
#define GRAPHICMODEL_HPP

#include <QKeyEvent>
#include <QMainWindow>
#include <vector>
#include <iostream>
#include <ctime>
#include "View.hpp"
#include "ViewAnswers.hpp"
#include "ViewPattern.hpp"

class Model;
class Pattern;
class GraphicModel : QObject
{
    Q_OBJECT
        class MyWindow : public QMainWindow {
        public:
            MyWindow () : QMainWindow() {}

        protected:
            void keyPressEvent(QKeyEvent *e) {
                if ( (e->key() == Qt::Key_Q) || (e->key() == Qt::Key_X) )
                    close();
            }
        };
private :
    MyWindow *window;
    std::vector<View*> views;
    Model *pModel;
    void close();
public:
    GraphicModel(Model *model); // constructor
    ~GraphicModel(); // destructor
    void setView(View *v); // set current view 'v'
    void refreshViews(); // refresh all views
    void show(); // show MyWindow
    void play(std::vector<Pattern *> const pPatterns); // start graphic quiz

};

#endif // GRAPHICMODEL_HPP
