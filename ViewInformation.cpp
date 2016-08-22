#include "ViewInformation.hpp"

// constructor
ViewInformation::ViewInformation(GraphicModel *pModel) : View(pModel)
{
    this->setFixedSize(GraphicModel::WIDTH, GraphicModel::HEIGHT);

    // create Vertical layout
    verticalLayout = new QVBoxLayout();
    verticalLayout->setContentsMargins(5, 5, 5, 5);

    // create QLabel containing the pattern's name
    patterName = new QLabel();
    patterName->setTextFormat(Qt::AutoText);
    patterName->setAlignment(Qt::AlignCenter);
    patterName->setMinimumSize(QSize(GraphicModel::WIDTH, 50));
    patterName->setMaximumSize(QSize(GraphicModel::WIDTH, 50));
    // QLabel's font : BOLD
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    font.setWeight(75);
    patterName->setFont(font);

    // Add it to the layout
    verticalLayout->addWidget(patterName);

    // create QLabel containing the pattern's image
    patternImage = new QLabel();
    this->patternImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // Add it to the layout
    verticalLayout->addWidget(patternImage);

    descriptionTitle = new QLabel("Description");
    descriptionTitle->setAlignment(Qt::AlignCenter);
    descriptionTitle->setMinimumSize(QSize(GraphicModel::WIDTH, 25));
    descriptionTitle->setMaximumSize(QSize(GraphicModel::WIDTH, 35));

    // QLabel's font : BOLD
    QFont font2;
    font2.setPointSize(12);
    font2.setItalic(true);
    font2.setUnderline(true);
    descriptionTitle->setFont(font2);

    // Add it to the layout
    verticalLayout->addWidget(descriptionTitle);

    // create QLabel containing the pattern's description and webpage link
    patternDescription = new QLabel();
    // QLabel's font : italic
    QFont font1;
    font1.setItalic(true);
    font1.setPointSize(12);
    patternDescription->setFont(font1);
    patternDescription->setAlignment(Qt::AlignCenter);
    patternDescription->setOpenExternalLinks(true);

    // Add it to the layout
    verticalLayout->addWidget(patternDescription);

    this->setLayout(this->verticalLayout);
}

// destructor
ViewInformation::~ViewInformation(){
    delete verticalLayout;
    delete patterName;
    delete patternImage;
    delete patternDescription;
}

void ViewInformation::refresh() const{

}

// fill fields
void ViewInformation::set(std::string const name, QPixmap *image, std::string const description, std::string const url){
    patterName->setText(QString::fromStdString(name));
    patternImage->setPixmap(*image);
    if(image->height() > ( this->height() / 2 ) || image->width() > ( this->width() / 2 )){
        patternImage->setScaledContents(true);
        patternImage->adjustSize();
    }
    QString descript(QString::fromStdString(description));
    descript.append("\nMore informations ");
    descript.append("<a href=\"");
    char * href = (char *)malloc(sizeof(char) * url.size());
    for(unsigned int i = 0 ; i < (url.size() - 1) ; i++){
        href[i] = url.at(i);
    }
    href[url.size() - 1] = '\0';
    descript.append(href);
    descript.append("\">here</a>");
    patternDescription->setTextFormat(Qt::RichText);
    patternDescription->setText(descript);
    patternDescription->adjustSize();
    patternDescription->setWordWrap(true);

    std::cout << "DONE set ViewInformation " << std::endl;
}
