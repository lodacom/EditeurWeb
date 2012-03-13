#include "Project.h"


Project::Project(string name, string parentPath):Element(name, parentPath){
    File projectFile(".pro", parentPath);
    //ifstream projectFileStream(parentPath << "/" <<".pro");
}

Project::~Project(){

}

