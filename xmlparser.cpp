#include "xmlparser.h"

#include <iostream>
#include <fstream>
#include "xmlelement.h"



SAXML::XMLParser::XMLParser(){}


SAXML::XMLParser::~XMLParser(){}


bool SAXML::XMLParser::loadFile(std::string& filePath){
    this->filePath=filePath;

    std::ifstream xml(filePath);
    if(xml.fail()){
        return false;
    }

    std::string history="";
    bool parse=false;
    int index=-1;
    int depth=0;
    char c=' ';

    while(!xml.eof()){
        //Parse until XML is relevant
        c=xml.get();
        history=history+c;
        if(history[history.length()-2]=='?' && history[history.length()-1]=='>'){
            parse=true;
            history="";
        }
        if(!parse){
            continue;
        }

        //Reduce depth
        if(history[history.length()-2]=='<' && history[history.length()-1]=='/'){
            depth--;
        }

        //Begin parsing an element
        if(history[history.length()-2]=='<' && history[history.length()-1]!='/' && history[history.length()-1]!='!' && !xml.eof()){
            depth++;

            //Skip characters until element name
            while(history[history.length()-1]==' ' && !xml.eof()){
                c=xml.get();
                history=history+c;
            }

            //Parse element name
            std::string elementName="";
            while(history[history.length()-1]!=' ' && history[history.length()-1]!='>' && history[history.length()-1]!='/' && !xml.eof()){
                elementName=elementName+history[history.length()-1];
                c=xml.get();
                history=history+c;
            }


            index++;
            this->element.push_back(SAXML::XMLElement(elementName, depth));

            std::cout<< elementName << " increase " << depth <<std::endl;

            if(history[history.length()-1]=='/'){
                depth--;
            }

            //std::cout << elementName << std::endl;

            //Parse any attributes
            if(history[history.length()-1]==' '){
                while(history[history.length()-1]!='>' && history[history.length()-1]!='/' && !xml.eof()){
                    //Skip characters until attribute name
                    while(history[history.length()-1]==' ' && !xml.eof()){
                        c=xml.get();
                        history=history+c;
                    }

                    //Parse attribute name
                    std::string attributeName="";
                    while(history[history.length()-1]!='=' && !xml.eof()){
                        attributeName=attributeName+history[history.length()-1];
                        c=xml.get();
                        history=history+c;
                    }

                    //std::cout<< "attributeName";
                    //std::cout<< attributeName <<std::endl;

                    //std::cout<<"check4";

                    //Skip characters until attribute value
                    while(history[history.length()-1]!=' ' && history[history.length()-1]!='"' && !xml.eof()){
                        c=xml.get();
                        history=history+c;
                    }
                    c=xml.get();
                    history=history+c;

                    //std::cout<<"check5";

                    //Parse attribute value
                    std::string attributeValue="";
                    while(history[history.length()-1]!='"' && !xml.eof()){
                        attributeValue=attributeValue+history[history.length()-1];
                        c=xml.get();
                        history=history+c;
                    }
                    this->element[index].appendAttribute(attributeName, attributeValue);

                    //std::cout<< "attributeValue";
                    //std::cout<< attributeValue <<std::endl;

                    c=xml.get();
                    history=history+c;

                    //std::cout<<"check6";
                }
                if(history[history.length()-1]=='/'){
                    depth--;
                }
            }
            //std::cout<< "check2";

            //Start parsing text
        }



    }

    //std::cout << history;

    return true;
}


int SAXML::XMLParser::size(){
    return this->element.size();
}


bool SAXML::XMLParser::getElement(SAXML::XMLElement **p, int index){
    if(index<this->size()){
        *p=&(this->element[index]);
        return true;
    }
    *p=nullptr;
    return false;
}


bool SAXML::XMLParser::getElement(SAXML::XMLElement **p, std::string &name){
    for(int i=0; i<this->size(); i++){
        if(this->element[i].getName()==name){
            *p=&(this->element[i]);
            return true;
        }
    }
    *p=nullptr;
    return false;
}


bool SAXML::XMLParser::appendElement(std::string& name, int depth){
    this->element.push_back(SAXML::XMLElement(name, depth));
    return true;
}


bool SAXML::XMLParser::removeElement(int index){
    if(index>=this->element.size()){
        return false;
    }
    this->element.erase(this->element.begin()+index);
    return true;
}







