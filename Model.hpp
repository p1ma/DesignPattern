#ifndef MODEL_HPP
#define MODEL_HPP

#include "GraphicModel.hpp"
#include "Pattern.hpp"
#include "FileReader.hpp"
#include <QPixmap>
#include <vector>

class Model
{
private :
    GraphicModel *pGraphicModel;
    std::vector<Pattern *> patterns;
    FileReader *pFileReader;
    void fillVector(); // fill the vector with all the patterns find in the directory patterns/informations/
public:
    Model();
    ~Model();
    std::string const getPatterns();
    void play(); // launch quiz
    QPixmap *getImage(std::string const name);
};

#endif // MODEL_HPP
