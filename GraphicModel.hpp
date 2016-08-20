#ifndef GRAPHICMODEL_HPP
#define GRAPHICMODEL_HPP

#include <QKeyEvent>
#include <QMainWindow>
#include <vector>
#include <iostream>
#include <ctime>
#include <QMessageBox>
#include <QColor>
#include "View.hpp"
#include "ViewQuiz.hpp"
#include "Pattern.hpp"

class Model;

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
    ViewQuiz *pViewQuiz;
    Model *pModel;
    std::vector<Pattern *> pPatterns;
    Pattern *rightAnswer;
    void close();
    std::vector<std::string> getOthersAnswers(int const index); // 4 answers, 1 correct ,3 incorrects, return the 3 incorrects
    void synchronize(std::vector<int> &list);
    void start();
    bool contains (int index, std::vector<int> &list);
    void erase(int index, std::vector<int> &list);
    void fillView(Pattern *pattern, std::vector<std::string> answers);
    std::vector<int> playlist; // all patterns at t=0
    std::vector<int> endlist; // patterns already find
public:
    GraphicModel(Model *model); // constructor
    ~GraphicModel(); // destructor
    void setView(View *v); // set current view 'v'
    void refreshViews(); // refresh all views
    void show(); // show MyWindow
    void play(std::vector<Pattern *> patterns); // start graphic quiz
    void copyToVector(std::vector<Pattern *> patterns); // copy patterns to pPatterns
    void handle(std::string answer);
    void setColor(QColor color); // set ViewQuiz color
    static const int WIDTH = 600;
    static const int HEIGHT = 800;
};

#endif // GRAPHICMODEL_HPP
