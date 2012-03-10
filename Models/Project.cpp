#include "Project.h"


Project::Project(string name = "", string parentPath = ""):Folder(name, parentPath){
    File projectFile(".pro", parentPath);
    //ifstream projectFileStream(parentPath << "/" <<".pro");
}

Project::~Project(){

}

