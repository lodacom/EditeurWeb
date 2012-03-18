#include "WorkSpaceTreeController.h"

WorkSpaceTreeController::WorkSpaceTreeController(){
    qItemModel = new QStandardItemModel();
}

WorkSpaceTreeController::~WorkSpaceTreeController(){

}

string WorkSpaceTreeController::getFilePath(list<int>* path){
    File* file = workSpace->getFile(path);
    if (file == NULL){
        return "";
    }
    else{
        return file->getPath();
    }
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
