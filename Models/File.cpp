#include "File.h"
File::File(string name, string parentPath):Element(name, parentPath){
    string extension;
    extension = getExtension();
    if(extension == "php"){
        qItem->setIcon(QIcon("Pics/File-PHP-icon.png"));
    }
    else if(extension == "html"){
        qItem->setIcon(QIcon("Pics/File-HTML-icon.png"));
    }
    else if(extension == "js"){
        qItem->setIcon(QIcon("Pics/File-JS-icon.png"));
    }
    else if(extension == "css"){
        qItem->setIcon(QIcon("Pics/File-CSS-icon.png"));
    }
    else{
        qItem->setIcon(QIcon("Pics/File-icon.png"));
    }
}

File::~File(){}

string File::getExtension(){
        if (name.find('.') == (size_t) -1){
            return "";
        }
        else{
            return name.substr(name.find_last_of('.') + 1, name.size());
        }
}


int File::getType(){
    return FILE_TYPE;
}


