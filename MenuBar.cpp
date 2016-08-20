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
    name = new QLineEdit(&dialog);
    description = new QTextEdit(&dialog);
    description->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    url = new QLineEdit(&dialog);
    image = new QLineEdit(&dialog);
    image->setText("click here");
    image->setReadOnly(true);
    connect(image, SIGNAL(selectionChanged()), this, SLOT(chooseFile()));
    form.addRow(new QLabel("Please fill this form."));
    form.addRow("Name : ", name);
    form.addRow("Description : ", description);
    form.addRow("Web page : ", url);
    form.addRow("Image path : ", image);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    form.addRow(&buttonBox);

    if (dialog.exec() == QDialogButtonBox::Ok) {

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

}

void MenuBar::reject(){

}
