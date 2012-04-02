#include "Element.h"

Element::Element(string name, string parentPath){
    this->name = name;
    this->parentPath = parentPath;
    this->parent = parent;
    this->qItem = new QStandardItem(QString(name.c_str()));
}

Element::~Element(){}

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
QStandardItem* Element::getQItem(int i){
    if(i){;}
    return qItem;
}
void Element::output(int prof){
    for (int i = 0; i < prof; i++)
	cout << "\t";
    cout << name << endl;
}

Element* Element::getElement(list<int>* accessList){
    if (accessList){;}
    return this;
}

void Element::deleteElement(){
    qItem->parent()->removeRow(qItem->row());
    remove(this->getPath().c_str());
}
void Element::dropElement(int i){
    if(i){;}
}
int Element::newFile(string fileName){
    if(fileName.empty()){;}
    return -1;
}
int Element::newFolder(string folderName){
    if(folderName.empty()){;}
    return -1;
}
int Element::getType(){
    return ELEMENT_TYPE;
}

int Element::renameFile(string newName){
    string path;
    path = parentPath + "/" + newName;
    int renamingResult = rename(this->getPath().c_str(), path.c_str());
    if(renamingResult == 0)
        this->name = newName;
    return renamingResult;
}
