#ifndef MODEL_HPP
#define MODEL_HPP

#include "GraphicModel.hpp"
#include "Pattern.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"
#include <QPixmap>
#include <vector>

class Model
{
private :
    GraphicModel *pGraphicModel;
    std::vector<Pattern *> patterns;
    FileReader *pFileReader;
    FileWriter *pFileWriter;
    void fillVector(); // fill the vector with all the patterns find in the directory patterns/informations/
public:
    Model();
    ~Model();
    std::string const getPatterns(); // return all patterns
    void play(); // launch quiz
    QPixmap *getImage(std::string const name); // return pattern 'name' image
    void add(std::string name, std::string url, std::string description, std::string image); // add a new pattern
    std::vector<Pattern *> getList();
};

#endif // MODEL_HPP
