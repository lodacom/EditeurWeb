#include "WorkSpaceTreeController.h"

WorkSpaceTreeController::WorkSpaceTreeController(){
    qItemModel = new QStandardItemModel();
    workSpace = new WorkSpace("WS", "/home/burger/Prog/CPP/QT/Projet/EditeurWebTest");
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
