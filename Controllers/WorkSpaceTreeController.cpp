#include "WorkSpaceTreeController.h"

WorkSpaceTreeController::WorkSpaceTreeController(){
    qItemModel = new QStandardItemModel();
}

WorkSpaceTreeController::~WorkSpaceTreeController(){

}

string WorkSpaceTreeController::getContentFromIndex(const QModelIndex &index){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    return element->getContent();
}

void WorkSpaceTreeController::setWorkSpace(string path){
    string parentPath, name;
    size_t lastSlashPos = path.find_last_of('/');
    parentPath = path.substr(0, lastSlashPos);
    name = path.substr(lastSlashPos + 1, path.size());
    workSpace = new WorkSpace(name, parentPath);
    workSpace->scan();
    workSpace->sort();
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

string WorkSpaceTreeController::getFileExtension(const QModelIndex& index){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    if (element->getType() != FILE_TYPE){
        return "";
    }
    else{
        string extension;
        extension = element->getPath();
        extension = extension.substr(extension.find_last_of('.') + 1, extension.length());
        return extension;
    }
}
int WorkSpaceTreeController::getElementType(const QModelIndex& index){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    return element->getType();
}

int WorkSpaceTreeController::newFile(const QModelIndex& index, string fileName, string content){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    return element->newFile(fileName, content);
}

//int WorkSpaceTreeController::pasteInFolder(const QModelIndex& index, string fileName, string content){
//    int newFileResult = newFile(index, fileName);
//    if(newFileResult != -1){
//        list<int> *accessList = indexToList(index);
//        Folder* fold = workSpace->getFolder(accessList);
//        File fil = fold->getFileByPosition(fold->findFilePosition(fileName));
//        fil.setContent(content);
//    }
//}

int WorkSpaceTreeController::newFolder(const QModelIndex& index, string folderName){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    return element->newFolder(folderName);
}

int WorkSpaceTreeController::newProject(string projectName){
    if (workSpace->findProjectPosition(projectName) != -1){
        return -1;
    }
    workSpace->newProject(projectName);
    Project *newProj = new Project(projectName, workSpace->getPath());
    File *proFile = new File(string(".pro"), newProj->getPath());
    newProj->addFile(proFile);
    workSpace->addProject(newProj);
    workSpace->sort();
    int projectPosition = workSpace->findProjectPosition(projectName);
    qItemModel->insertRow(projectPosition, newProj->getQItem());
    return 0;
}

void WorkSpaceTreeController::deleteFile(const QModelIndex& index){
    list<int> *accessList = indexToList(index);
    if(accessList->size() > 1){
        Element *parentElement;
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

string WorkSpaceTreeController::getNameFromIndex(const QModelIndex& index){
    list<int> *accessList = indexToList(index);
    Element* element = workSpace->getElement(accessList);
    return element->getName();
}

int WorkSpaceTreeController::renameFile(const QModelIndex &index, string newName){
    list<int> *accessList = indexToList(index);
    int ok;
    if(accessList->size() > 1){
        Element *parentElement;
        int sonIndex = accessList->back();
        accessList->pop_back();
        parentElement = workSpace->getElement(accessList);
        ok = parentElement->renameElement(sonIndex, newName);
    }
    else{
        ok = workSpace->renameElement(accessList->back(), newName);
        int newPosition = workSpace->findProjectPosition(newName);
        qItemModel->insertRow(newPosition, qItemModel->takeRow(accessList->back()));
    }
    return ok;
}

