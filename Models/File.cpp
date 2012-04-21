#include "File.h"
File::File(string name, string parentPath):Element(name, parentPath){
    string extension;
    extension = getExtension();
    if(extension == "php"){
        qItem->setIcon(*Tools::phpIcon);
    }
    else if(extension == "html"){
        qItem->setIcon(*Tools::htmlIcon);
    }
    else if(extension == "js"){
        qItem->setIcon(*Tools::jsIcon);
    }
    else if(extension == "css"){
        qItem->setIcon(*Tools::cssIcon);
    }
    else{
        qItem->setIcon(*Tools::fileIcon);
    }
}

File::~File(){

}

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
