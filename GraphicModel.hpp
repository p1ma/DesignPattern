#ifndef GRAPHICMODEL_HPP
#define GRAPHICMODEL_HPP

#include <QKeyEvent>
#include <QMainWindow>
#include <vector>
#include "View.hpp"
#include "ViewAnswers.hpp"
#include "ViewPattern.hpp"

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
    Model *pModel;
public:
    GraphicModel(Model *model);
    ~GraphicModel();
    void setView(View *v);
    void refreshViews();
};

#endif // GRAPHICMODEL_HPP
