#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <string>
#include <vector>
#include "xmlelement.h"
#include <iostream>
#include <fstream>

namespace SAXML{



class XMLParser{
public:
    XMLParser();
    ~XMLParser();

    bool loadFile(std::string &filePath);

    std::string getFilePath();

    int size();

    bool getElement(XMLElement **p, int index);
    bool getElement(XMLElement **p, std::string &name);
    bool getElement(XMLElement **p, const std::string &name);

    bool appendElement(std::string &name, int depth);
    bool removeElement(int index);


private:
    std::string filePath;
    std::vector<XMLElement> element;
};



};

#endif // XMLPARSER_H
