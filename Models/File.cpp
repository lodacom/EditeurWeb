#include "File.h"
File::File(string name, string parentPath, string extension):Element(name, parentPath){
    this->extension = extension;
    qItem->setIcon(QIcon("/home/jo/git/EditeurWebLocal/Pics/File-icon.png"));
}

File::~File(){}

string File::getExtension(){
    return extension;
}

void File::setExtension(string extension){
    this->extension = extension;
}

