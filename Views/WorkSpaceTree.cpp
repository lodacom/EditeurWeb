#include "WorkSpaceTree.h"
#include "../Controllers/WorkSpaceTreeController.h"
WorkSpaceTree::WorkSpaceTree(){
    WorkSpaceTreeController *wsController = new WorkSpaceTreeController();
    this->setModel(wsController->getQItemModel());

}

WorkSpaceTree::~WorkSpaceTree(){

}
