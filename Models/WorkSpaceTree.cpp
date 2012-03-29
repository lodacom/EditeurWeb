#include "LeftTree.h"
#include "../Controllers/WorkSpaceTreeController.h"
LeftTree::LeftTree(){
    WorkSpaceTreeController *wsController = new WorkSpaceTreeController();
    this->setModel(wsController->getQItemModel());
}

LeftTree::~LeftTree(){

}
