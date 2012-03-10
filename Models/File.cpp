#include "File.h"

File::File(string name, string parentPath, string extension):Element(name, parentPath){
    this->extension = extension;
}

File::~File(){}

string File::getExtension(){
    return extension;
}

void File::setExtension(string extension){
    this->extension = extension;
}

