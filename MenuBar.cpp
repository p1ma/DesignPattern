#include "MenuBar.hpp"

MenuBar::MenuBar(GraphicModel* const graphic) : QMenuBar(0), pGraphicModel(graphic)
{
    // MENU "File"
    this->file = new QMenu("File");
        // QACTION EXIT
    this->exit = new QAction(tr("&Exit"), this->file);
    connect(this->exit, SIGNAL(triggered()), this, SLOT(exitWindow()));
    this->file->addAction(this->exit);

    // MENU "Patterns"
    this->patternInfos = new QMenu("Pattern");
        // QACTION ADD NEW PATTERN
    this->addPattern = new QAction(tr("&New pattern"), this->patternInfos);
    connect(this->addPattern, SIGNAL(triggered()), this, SLOT(addNewPattern()));
    // MENU "Quiz"
    this->quiz = new QMenu("Quiz");
    this->start = new QAction(tr("&Start Quiz"), this->quiz);
    connect(this->start, SIGNAL(triggered()), this, SLOT(startQuiz()));
    this->quiz->addAction(this->start);

        // QMENU INFORMATION
    this->informations = new QMenu(tr("&Informations"));
    //fillQActions();
    std::vector<Pattern *> pPatterns = pGraphicModel->getList();
    for(unsigned int i = 0 ; i < pPatterns.size() ; i++){
        QAction *a = new QAction(tr(pPatterns[i]->getName().c_str()),this->informations);
        this->pPatternList.push_back(a);
        connect(a, SIGNAL(triggered()), this, SLOT(seeInformations()));
    }

    // fill QMenu informations
    this->informations->addActions(pPatternList);

    this->patternInfos->addAction(this->addPattern);
    this->patternInfos->addMenu(this->informations);


    // ADD MENU TO MENUBAR
    this->addMenu(this->file);
    this->addMenu((this->patternInfos));
    this->addMenu(this->quiz);
}

MenuBar::~MenuBar(){
    delete this->file;
    delete this->informations;
    delete this->patternInfos;
}

void MenuBar::exitWindow(){
    this->pGraphicModel->close();
}

void MenuBar::addNewPattern(){
    QDialog dialog(this);
    dialog.setWindowTitle("AddGo Jun Hee  new pattern");
    QFormLayout form(&dialog);
    name = new QLineEdit(&dialog);
    description = new QTextEdit(&dialog);
    description->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    url = new QLineEdit(&dialog);
    image = new QLineEdit(&dialog);
    image->setText("double click here");
    image->setReadOnly(true);
    connect(image, SIGNAL(selectionChanged()), this, SLOT(chooseFile()));
    form.addRow(new QLabel("Please fill this form."));
    form.addRow("Name : ", name);
    form.addRow("Description : ", description);
    form.addRow("Web page : ", url);
    form.addRow("Image path : ", image);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    form.addRow(&buttonBox);

    if (dialog.exec() == QDialog::Accepted){
        // user clicked on 'ok'
        accept();
    }else{
        // user clicked on 'cancel'
        reject();
    }
}

void MenuBar::chooseFile(){
    QFileDialog dialog;
    QString filter = tr("PNG (*.png)");
    dialog.setFileMode(QFileDialog::ExistingFile);
    QStringList list = dialog.getOpenFileNames(this, "Select a file...", QDir::homePath(), tr("PNG (*.png)"), &filter);
    if(list.size() > 0){
        this->image->setText(list.at(0));
    }
}

void MenuBar::accept(){
        QString formName, formUrl, formDescription, formImage;
        // get user's answers
        formName = name->text();
        formUrl = url->text();
        formDescription = description->toPlainText();
        formImage = image->text();
        // check if formUrl is a webpage URL
        bool begin = (formUrl.startsWith("http://") || formUrl.startsWith("https://")) && formImage.startsWith("/");
        // check if form* are empties or incorrects
        bool ok = (formName.isEmpty() || formUrl.isEmpty() || formDescription.isEmpty() || formImage.isEmpty());
        if(ok || !begin){
            // one of them (at least) is empty
            QMessageBox::information(this, "Error", "Incorrect(s) field(s) !");
        }else{
            QMessageBox::information(this, "Success", "Design Pattern added.\n Restart app please.");
            pGraphicModel->add(formName.toStdString(), formUrl.toStdString(), formDescription.toStdString(), formImage.toStdString());
        }
}

void MenuBar::reject(){
    // cancel = no action to do
}

// select pattern
void MenuBar::seeInformations(){
    QAction *action = qobject_cast<QAction *>(this->sender());
    if(action != NULL){
        unsigned int index = pPatternList.indexOf(action,0);
        std::vector<Pattern *> pPatterns = pGraphicModel->getList();
        Pattern *p = pPatterns[index];
        this->pGraphicModel->setViewInformation(p);
    }
}

// start the Quiz
void MenuBar::startQuiz(){
    this->pGraphicModel->setViewQuiz();
}
