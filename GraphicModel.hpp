#ifndef GRAPHICMODEL_HPP
#define GRAPHICMODEL_HPP

#include <QKeyEvent>
#include <QMainWindow>
#include <vector>
#include <iostream>
#include <ctime>
#include <QMessageBox>
#include <QColor>
#include <QMenuBar>
#include <QMenu>
#include "View.hpp"
#include "ViewQuiz.hpp"
#include "ViewStart.hpp"
#include "Pattern.hpp"

class Model;
class MenuBar;
class ViewInformation;

class GraphicModel : QObject
{
    Q_OBJECT
        class MyWindow : public QMainWindow {
        public:
            MyWindow () : QMainWindow(0) {
            }

        protected:
            void keyPressEvent(QKeyEvent *e) {
                if ( (e->key() == Qt::Key_Q) || (e->key() == Qt::Key_X) )
                    close();
            }
        };
private :
    MyWindow *window;
    MenuBar *pMenuBar;
    std::vector<View*> views;
    ViewQuiz *pViewQuiz;
    ViewInformation *pViewInformation;
    ViewStart *pViewStart;
    Model *pModel;
    std::vector<Pattern *> pPatterns;
    Pattern *rightAnswer;
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
    void launch() ; // default graphic interface, just colored window
    void setView(View *v); // set current view 'v'
    void refreshViews(); // refresh all views
    void show(); // show MyWindow
    void play(std::vector<Pattern *> patterns); // start graphic quiz
    void copyToVector(std::vector<Pattern *> patterns); // copy patterns to pPatterns
    void handle(std::string answer);
    void setColor(QColor color); // set ViewQuiz color
    void close();
    void add(std::string name, std::string url, std::string description, std::string image);
    void updateList(std::vector<Pattern *> patterns);
    unsigned int getSize(); // return pPatterns.size()
    std::vector<Pattern *> getList(); //return pPatterns
    void setViewInformation(Pattern *pPattern); // fill viewInformation fields
    void setViewQuiz(); // set ViewQuiz as mainWidget
    static const int WIDTH = 600;
    static const int HEIGHT = 800;
};

#endif // GRAPHICMODEL_HPP
