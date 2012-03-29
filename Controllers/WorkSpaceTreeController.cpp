#include "WorkSpaceTreeController.h"

WorkSpaceTreeController::WorkSpaceTreeController(){
    qItemModel = new QStandardItemModel();
}

WorkSpaceTreeController::~WorkSpaceTreeController(){

}

void WorkSpaceTreeController::setWorkSpace(string path){
    string parentPath, name;
    size_t lastSlashPos = path.find_last_of('/');
    parentPath = path.substr(0, lastSlashPos);
    name = path.substr(lastSlashPos + 1, path.size());
    workSpace = new WorkSpace(name, parentPath);
    workSpace->scan();
    QStandardItem *wsItem = workSpace->getQItem();
    qItemModel->clear();
    for (int i = 0; i < wsItem->rowCount(); i++){
        qItemModel->appendRow(wsItem->takeChild(i));
    }
    qItemModel->setHeaderData(0, Qt::Horizontal, "Projects", Qt::DisplayRole);
    wsItem->~QStandardItem();
}

QStandardItemModel* WorkSpaceTreeController::getQItemModel(){
    return qItemModel;
}

list<int>* WorkSpaceTreeController::indexToList(const QModelIndex& index){
    list<int> *accessList = new list<int>();
    QModelIndex indexCopy = QModelIndex(index);
    while (indexCopy != QModelIndex()){
        accessList->push_front(indexCopy.row());
        indexCopy = indexCopy.parent();
    }
    return accessList;
}

string WorkSpaceTreeController::getFilePath(const QModelIndex& index){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    if (element->getType() != FILE_TYPE){
        return "";
    }
    else{
        return element->getPath();
    }
}

void WorkSpaceTreeController::deleteFile(const QModelIndex& index){
    list<int> *accessList = indexToList(index);
    Element *parentElement;
    if(accessList->size() > 1){
        int sonIndex = accessList->back();
        accessList->pop_back();
        parentElement = workSpace->getElement(accessList);
        parentElement->dropElement(sonIndex);
    }
    else{
        workSpace->dropElement(accessList->back());
        qItemModel->removeRow(accessList->back());
    }
}
