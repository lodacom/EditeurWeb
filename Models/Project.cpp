#include "Project.h"


Project::Project(string name, string parentPath):Element(name, parentPath), Folder(name, parentPath){
    //ifstream projectFileStream(parentPath << "/" <<".pro");
    qItem->setIcon(QIcon("/home/jo/git/EditeurWebLocal/Pics/Project-icon.png"));
}

Project::~Project(){

}

int Project::getType(){
    return PROJECT_TYPE;
}

void Project::deleteElement(){
        for(size_t i=0; i < folders.size(); i++){
            folders[i].deleteElement();
        }
        for(size_t i=0; i <files.size();i++){
            files[i].deleteElement();
        }
        delete qItem;
        remove(this->getPath().c_str());
}
