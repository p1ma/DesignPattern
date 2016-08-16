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
    std::vector<Pattern *> pPatterns;
    void close();
    std::vector<std::string> getOthersAnswers(std::string const goodOne); // 4 answers, 1 correct ,3 incorrects, return the 3 incorrects
    void synchronize(std::vector<int> &list);
    void start(std::vector<int> playlist, std::vector<int> endlist);
    bool contains(unsigned int index, std::vector<int> &list);
    void erase(unsigned int index, std::vector<int> &list);
public:
    GraphicModel(Model *model); // constructor
    ~GraphicModel(); // destructor
    void setView(View *v); // set current view 'v'
    void refreshViews(); // refresh all views
    void show(); // show MyWindow
    void play(std::vector<Pattern *> patterns); // start graphic quiz
    void copyToVector(std::vector<Pattern *> patterns); // copy patterns to pPatterns

};

#endif // GRAPHICMODEL_HPP
