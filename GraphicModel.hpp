#ifndef GRAPHICMODEL_HPP
#define GRAPHICMODEL_HPP

#include <QKeyEvent>
#include <QMainWindow>

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
public:
    GraphicModel();
    ~GraphicModel();
};

#endif // GRAPHICMODEL_HPP
