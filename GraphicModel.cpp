#include "GraphicModel.hpp"

#include "Model.hpp"
#include "MenuBar.hpp"
#include "ViewInformation.hpp"

// constructor
GraphicModel::GraphicModel(Model *model) : QObject(), pModel(model)
{
    this->window = new MyWindow();
    this->window->setFixedSize(WIDTH,HEIGHT);
    this->window->setWindowTitle(QString::fromUtf8("Pattern Quiz") );
    this->window->setStyleSheet("QMainWindow {background: 'beige';}");

    // MENUBAR
    this->pMenuBar = new MenuBar(this);
    this->window->setMenuBar(this->pMenuBar);
    this->window->menuBar()->setVisible(true);

    // instanciate views
    this->pViewQuiz = new ViewQuiz(this);
    this->pViewInformation = new ViewInformation(this);
    this->pViewStart = new ViewStart(this);
    views.push_back(this->pViewQuiz);
    views.push_back(this->pViewInformation);
    views.push_back(this->pViewStart);
    srand(std::time(0)); // for rand() function
    setColor(QColor(234,234,180)); // beige
}

// destructor
GraphicModel::~GraphicModel(){
    this->window->close();
    delete this->pViewQuiz;
    delete this->pViewInformation;
    delete this->window;
}

// default graphic interface, just colored window
void GraphicModel::launch(){
    setView(this->pViewStart);
    this->show();
}

// change current view
void GraphicModel::setView(View *v){
    QWidget *setWindow = this->window->centralWidget();
    if(setWindow != NULL){
        setWindow->setParent(0);
    }
    this->window->setCentralWidget(v);
    this->window->setMenuBar(this->pMenuBar);
    this->window->menuBar()->setVisible(true);
    this->show();
}

// refresh all views
void GraphicModel::refreshViews(){
    for(unsigned int i = 0 ; i < views.size() ; i++){
        views[i]->refresh();
    }
}

// ask MyWindow to show
void GraphicModel::show(){
    this->window->show();
}

// play graphic quiz
void GraphicModel::play(std::vector<Pattern *> patterns){
    // if there is at least 1 pattern in the directory /patterns/informations/
    this->playlist.clear();
    this->endlist.clear();
    if(patterns.size() > 4){
        copyToVector(patterns); // copy patterns vector to pPatterns
        synchronize(this->playlist);
        start(); // start playing
    }else{
        std::cout << "Quiz not available." << std::endl
                     << "Please add patterns informations in /patterns/informations/" << std::endl
                        <<"And image (.png) in /patterns/images/" << std::endl;
        close();
    }
}

// close all
void GraphicModel::close(){
    // need timer or smth
    this->window->close();
}

 // 4 answers, 1 correct ,3 incorrects, return the 3 incorrects
std::vector<std::string> GraphicModel::getOthersAnswers(int const index){
    std::vector<std::string> answers;
    std::vector<int> list;
    list.push_back(index);
    answers.push_back(this->pPatterns[index]->getName());
    unsigned int pick;
    while(answers.size() < 4){
        while(contains(pick,list)){
        pick = (rand() % (this->pPatterns.size())); // pick a random number € [0, nbPattern-1]
        }
        list.push_back(pick);
        answers.push_back(this->pPatterns[pick]->getName());
    }
    return answers;
}

void GraphicModel::copyToVector(std::vector<Pattern *> patterns){
    this->pPatterns.swap(patterns); // error 14/08/2016 22h41
}

// put every pattern's index from pPattern to list
void GraphicModel::synchronize(std::vector<int> &list){
    for(unsigned int i = 0 ; i < this->pPatterns.size() ; i++){
        list.push_back(i);
    }
}

void GraphicModel::start(){
    int index = (rand() % this->pPatterns.size()); // pick a random number € [0, nbPattern-1];
    std::vector<std::string> answers;
    // there is at least 1 DP in the list
    if(this->playlist.size() > 0){
        while(contains(index,this->endlist)){
            index = (rand() % (this->pPatterns.size())); // pick a random number € [0, nbPattern-1]
        }
        this->rightAnswer = this->pPatterns[index]; // obv
        this->endlist.push_back(index); // add element
        erase(index, this->playlist) ; // remove element
        answers = getOthersAnswers(index);
        fillView(this->pPatterns[index], answers); // fill the ViewQuiz
    }else{
     // No more DP , the quiz is finished
        QMessageBox::StandardButtons msgBox; // YES / NO Button
        std::ostringstream nb;
        nb << this->pPatterns.size();
        QString msg = "You achieved the " + QString::fromStdString(nb.str()) + " questions with success." +
                "\nDo you want to play again ?";
        msgBox = QMessageBox::question(pViewQuiz,"Congratulation", msg, QMessageBox::Yes | QMessageBox::No);
        if(msgBox == QMessageBox::Yes){
                // reload the quiz
            play(this->pPatterns);
        }else{
            // quit
            close();
        }
    }
}

// check if 'index' is present in the vector 'list'
bool GraphicModel::contains(int index, std::vector<int> &list){
    if (std::find(list.begin(), list.end(), index) != list.end())
    {
        return true;
    }
    return false;
}

// erase element 'index' in the vector 'list'
void GraphicModel::erase(int index, std::vector<int> &list){
    for(unsigned int i = 0 ; i < list.size() ; i++){
        if(list[i] == index){
            list.erase(list.begin() + i);
            return;
        }
    }
}

void GraphicModel::handle(std::string answer){
    if((rightAnswer->getName()).compare(answer) == 0){
        QString msg = QString::fromStdString(rightAnswer->getDescription());
        msg.append("<br>More infos ");
        msg.append("<a href=\"");
        std::string url = rightAnswer->getURL();
        char * href = (char *)malloc(sizeof(char) * url.size());
        for(unsigned int i = 0 ; i < (url.size() - 1) ; i++){
            href[i] = url.at(i);
        }
        href[url.size() - 1] = '\0';
        msg.append(href);
        msg.append("\">here</a>");
        // URL problem with factory
        QMessageBox msgBox(pViewQuiz);
        msgBox.setWindowTitle("Congratulation");
        msgBox.setTextFormat(Qt::RichText);
        msgBox.setText(msg);
        // need to change the question now...
        if(msgBox.exec() == QMessageBox::Ok){
            start();
        }
    }
}

void GraphicModel::fillView(Pattern *pattern, std::vector<std::string> answers){
    QPixmap *pImage = this->pModel->getImage(pattern->getImageName());
    this->pViewQuiz->setQuestion(pImage,answers);
}

//set ViewQuiz's color
void GraphicModel::setColor(QColor color){
    this->pViewInformation->setColor(color);
    this->pViewQuiz->setColor(color);
}

//Add a new Pattern to the pattern pool
void GraphicModel::add(std::string name, std::string url, std::string description, std::string image){
    this->pModel->add(name,url,description,image);
}

// update the pattern list
void GraphicModel::updateList(std::vector<Pattern *> patterns){
    //this->window->update();
    //play(patterns);
}

// return pPattern size
unsigned int GraphicModel::getSize(){
    return pPatterns.size();
}

//return pPatterns
std::vector<Pattern *> GraphicModel::getList(){
    return pModel->getList();
}

// fill viewInformation fields
void GraphicModel::setViewInformation(Pattern *pPattern){
    QPixmap *p = this->pModel->getImage(pPattern->getImageName());
    std::string name = pPattern->getName();
    std::string description = pPattern->getDescription();
    std::string url = pPattern->getURL();
    setView(this->pViewInformation);
    this->pViewInformation->set(name,p,description,url);
}

// set ViewQuiz as mainWidget
void GraphicModel::setViewQuiz(){
    setView(pViewQuiz);
    play(pModel->getList());
}
