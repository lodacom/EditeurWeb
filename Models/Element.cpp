#include "Element.h"

Element::Element(string name, string parentPath){
    this->name = name;
    this->parentPath = parentPath;
    qItem = new QStandardItem(QString(name.c_str()));
}

Element::~Element(){};

string Element::getName(){
    return name;
}

void Element::setName(string name){
    this->name = name;
}

string Element::getParentPath(){
    return parentPath;
}

void Element::setParentPath(string parentPath){
    this->parentPath = parentPath;
}

string Element::getPath(){
    string path;
    path = parentPath + "/" + name;
    return path;
}

void Element::output(int prof){
    for (int i = 0; i < prof; i++)
	cout << "\t";
    cout << name << endl;
}

QStandardItem* Element::getQItem(){
    return qItem;
}
