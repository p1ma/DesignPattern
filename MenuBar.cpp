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
        // QACTION INFORMATIONS
    this->informations = new QAction(tr("&Informations"), this->patternInfos);
    this->patternInfos->addAction(this->addPattern);
    this->patternInfos->addAction(this->informations);


    // ADD MENU TO MENUBAR
    this->addMenu(this->file);
    this->addMenu((this->patternInfos));
}

MenuBar::~MenuBar(){
    delete this->file;
    delete this->patternInfos;
}

void MenuBar::exitWindow(){
    this->pGraphicModel->close();
}

void MenuBar::addNewPattern(){
    QDialog dialog(this);
    dialog.setWindowTitle("Add new pattern");
    QFormLayout form(&dialog);
    QLineEdit *name = new QLineEdit(&dialog);
    QTextEdit *description = new QTextEdit(&dialog);
    description->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    QLineEdit *url = new QLineEdit(&dialog);
    QLineEdit *image = new QLineEdit(&dialog);
    image->setText("click here");
    image->setReadOnly(true);
    connect(image, SIGNAL(clicked()), this, SLOT(chooseFile()));
    form.addRow(new QLabel("Please fill this form."));
    form.addRow("Name : ", name);
    form.addRow("Description : ", description);
    form.addRow("Web page : ", url);
    form.addRow("Image path : ", image);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    if (dialog.exec() == QDialog::Accepted) {

    }
}

void MenuBar::chooseFile(){
    QFileDialog::getOpenFileNames(this, "Select a file to open...", QDir::homePath());
}
