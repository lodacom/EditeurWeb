#include "WorkSpaceTree.h"

WorkSpaceTree::WorkSpaceTree(){
    wsController = new WorkSpaceTreeController();
    model = wsController->getQItemModel();
    this->setModel(model);
    this->setEditTriggers(NoEditTriggers);
    this->setExpandsOnDoubleClick(true);

}
void WorkSpaceTree::selectWorkSpace(string path){
    wsController->setWorkSpace(path);
}

WorkSpaceTree::~WorkSpaceTree(){

}
string WorkSpaceTree::getFilePath(list<int>* workSpacePath){
    return wsController->getFilePath(workSpacePath);
}
