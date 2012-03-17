#include "WorkSpaceTreeController.h"

WorkSpaceTreeController::WorkSpaceTreeController(){
    qItemModel = new QStandardItemModel();
    workSpace = new WorkSpace("WSworkspace", "/home/jo");
    workSpace->scan();
    QStandardItem *wsItem = workSpace->getQItem();
    for (int i = 0; i < wsItem->rowCount(); i++){
        qItemModel->appendRow(wsItem->takeChild(i));
    }
    qItemModel->setHeaderData(0, Qt::Horizontal, "Projects", Qt::DisplayRole);
    wsItem->~QStandardItem();
}

WorkSpaceTreeController::~WorkSpaceTreeController(){

}

QStandardItemModel* WorkSpaceTreeController::getQItemModel(){
    return qItemModel;
}
