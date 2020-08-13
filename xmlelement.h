#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <string>
#include <vector>

namespace SAXML{



class XMLElement{
public:
    XMLElement(std::string& name, int depth);
    ~XMLElement();

    std::string getName();
    int getDepth();

    int size();

    std::string getAttribute(int index);
    bool setAttribute(int index, std::string& attribute);

    std::string getValue(int index);
    std::string getValue(std::string& attribute);
    bool setValue(int index, std::string& value);
    bool setValue(std::string& attribute, std::string& value);

    bool appendAttribute(std::string& attribute, std::string& value);
    bool removeAttribute(int index);

private:
    std::string name;
    int depth;
    std::vector<std::string> attribute;
    std::vector<std::string> value;
};



}

#endif // XMLELEMENT_H
