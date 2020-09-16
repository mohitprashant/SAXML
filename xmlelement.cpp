#include "xmlelement.h"

SAXML::XMLElement::XMLElement(std::string &name, int depth) : name(name), depth(depth) {}


SAXML::XMLElement::~XMLElement(){}


std::string SAXML::XMLElement::getName(){
    return this->name;
}


int SAXML::XMLElement::getDepth(){
    return this->depth;
}


int SAXML::XMLElement::size(){
    return this->attribute.size();
}


std::string SAXML::XMLElement::getAttribute(int index){
    return this->attribute[index];
}


bool SAXML::XMLElement::setAttribute(int index, std::string &attribute){
    this->attribute[index]=attribute;
    return true;
}


std::string* SAXML::XMLElement::getRef(int index){
    if(index>this->value.size()){
        return nullptr;
    }
    return &(this->value[index]);
}



std::string* SAXML::XMLElement::getRef(std::string &attribute){
    for(int i=0; i<this->value.size(); i++){
        if(this->attribute[i]==attribute){
            return &(this->value[i]);
        }
    }
    return nullptr;
}



std::string* SAXML::XMLElement::getRef(const std::string &attribute){
    for(int i=0; i<this->value.size(); i++){
        if(this->attribute[i]==attribute){
            return &(this->value[i]);
        }
    }
    return nullptr;
}


std::string SAXML::XMLElement::getValue(int index){
    if(index>this->value.size()){
        return "invalid index";
    }
    return this->value[index];
}


std::string SAXML::XMLElement::getValue(std::string &attribute){
    for(int i=0; i<this->value.size(); i++){
        if(this->attribute[i]==attribute){
            return this->value[i];
        }
    }
    return "invalid attribute";
}



std::string SAXML::XMLElement::getValue(const std::string &attribute){
    for(int i=0; i<this->value.size(); i++){
        if(this->attribute[i]==attribute){
            return this->value[i];
        }
    }
    return "invalid attribute";
}



bool SAXML::XMLElement::setValue(int index, std::string &value){
    this->value[index]=value;
    return true;
}


bool SAXML::XMLElement::setValue(std::string &attribute, std::string &value){
    for(int i=0; i<this->attribute.size(); i++){
        if(this->attribute[i]==attribute){
            this->value[i]=value;
            return true;
        }
    }
    return false;
}



bool SAXML::XMLElement::setValue(const std::string &attribute, std::string &value){
    for(int i=0; i<this->attribute.size(); i++){
        if(this->attribute[i]==attribute){
            this->value[i]=value;
            return true;
        }
    }
    return false;
}



bool SAXML::XMLElement::appendAttribute(std::string &attribute, std::string &value){
    this->attribute.push_back(attribute);
    this->value.push_back(value);
    return true;
}


bool SAXML::XMLElement::removeAttribute(int index){
    this->attribute.erase(this->attribute.begin()+index);
    this->value.erase(this->value.begin()+index);
    return true;
}






