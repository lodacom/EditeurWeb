#include "Project.h"


Project::Project(string name, string parentPath):Element(name, parentPath), Folder(name, parentPath){
    //ifstream projectFileStream(parentPath << "/" <<".pro");
    qItem->setIcon(QIcon("/home/jo/git/EditeurWebLocal/Pics/Project-icon.png"));
}

Project::~Project(){

}

