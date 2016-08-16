#include "GraphicModel.hpp"

// constructor
GraphicModel::GraphicModel(Model *model) : QObject(), pModel(model)
{
    this->window = new MyWindow();
    this->window->setFixedSize(WIDTH,HEIGHT);
    this->window->setWindowTitle(QString::fromUtf8("Pattern Quiz") );
    //this->window->show();

    // instanciate views
    //ViewAnswers *answers = new ViewAnswers(this);
    //ViewPattern *pattern = new ViewPattern(this);
    ViewQuiz *quiz = new ViewQuiz(this);
    //views.push_back(answers);
    //views.push_back(pattern);
    views.push_back(quiz);
    srand(std::time(0)); // for random function
    setView(quiz);
}

// destructor
GraphicModel::~GraphicModel(){
    delete this->window;
}

// change current view
void GraphicModel::setView(View *v){
    this->window->setCentralWidget(v);
    this->window->show();
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
    if(patterns.size() > 4){
        copyToVector(patterns); // copy patterns vector to pPatterns
        std::vector<int> playlist; // all patterns at t=0
        std::vector<int> endlist; // patterns already find
        std::cout << "synchronize " << std::endl;
        synchronize(playlist);
        std::cout << "start playin'" << std::endl;
        start(playlist,endlist); // start playing
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
    //delete this->pModel;
    return;
}

 // 4 answers, 1 correct ,3 incorrects, return the 3 incorrects
std::vector<std::string> GraphicModel::getOthersAnswers(std::string const goodOne){
    std::vector<std::string> answers;

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

void GraphicModel::start(std::vector<int> playlist, std::vector<int> endlist){
    unsigned int index = (rand() % this->pPatterns.size()); // pick a random number € [0, nbPattern-1];
    while(playlist.size() > 0){
        while(contains(index,endlist)){
            index = (rand() % (this->pPatterns.size())); // pick a random number € [0, nbPattern-1]
        }
        std::cout << "index picked " << index << std::endl;
        endlist.push_back(index); // add element
        erase(index, playlist) ; // remove element
    }
}

// check if 'index' is present in the vector 'list'
bool GraphicModel::contains(unsigned int index, std::vector<int> &list){
    if (std::find(list.begin(), list.end(), index) != list.end())
    {
        return true;
    }
    return false;
}

// erase element 'index' in the vector 'list'
void GraphicModel::erase(unsigned int index, std::vector<int> &list){
    for(unsigned int i = 0 ; i < list.size() ; i++){
        if(list[i] == index){
            list.erase(list.begin() + i);
            return;
        }
    }
}
