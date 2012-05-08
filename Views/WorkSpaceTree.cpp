#include "WorkSpaceTree.h"

WorkSpaceTree::WorkSpaceTree(){
    wsController = new WorkSpaceTreeController();
    model = wsController->getQItemModel();
    workSpaceEtablished = false;
    indexFileToCopy = QModelIndex();
    this->setMinimumWidth(200);
    this->setupMenus();
    this->setModel(model);
    this->setEditTriggers(NoEditTriggers);
    this->setExpandsOnDoubleClick(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(wsController, SIGNAL(newWorkSpace()), this, SLOT(setWSModel()));
    QObject::connect(this, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(getFilePath(const QModelIndex &)));
}

WorkSpaceTree::~WorkSpaceTree(){

}

void WorkSpaceTree::setupMenus(){
    fileMenu = new QMenu(this);
    folderMenu = new QMenu(this);
    QAction* openAction = new QAction(tr("&Open"),this);
    QAction* copyAction = new QAction(tr("&Copy"),this);
    QAction* cutAction = new QAction(tr("C&ut"),this);
    QAction* saveAction = new QAction(tr("&Save"),this);
    QAction* deleteAction = new QAction(tr("&Delete"),this);
    QAction* renameAction = new QAction(tr("&Rename"),this);
    QAction* newFileAction = new QAction(tr("&Add File"), this);
    QAction* newFolderAction = new QAction(tr("&Add Folder"), this);
    QAction* pasteAction = new QAction(tr("&Paste"),this);
    fileMenu->addAction(openAction);
    fileMenu->addAction(copyAction);
    fileMenu->addAction(cutAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(deleteAction);
    fileMenu->addAction(renameAction);
    folderMenu->addAction(newFileAction);
    folderMenu->addAction(newFolderAction);
    folderMenu->addAction(pasteAction);
    folderMenu->addAction(renameAction);
    folderMenu->addAction(deleteAction);
    QObject::connect(deleteAction, SIGNAL(triggered()), this ,SLOT(deleteFileFromPos()));
    QObject::connect(openAction,SIGNAL(triggered()),this,SLOT(openFileFromPos()));
    QObject::connect(copyAction, SIGNAL(triggered()),this,SLOT(copyFileFromPos()));
    QObject::connect(cutAction, SIGNAL(triggered()),this,SLOT(cutFileFromPos()));
    QObject::connect(pasteAction,SIGNAL(triggered()),this,SLOT(pasteFileFromPos()));
    QObject::connect(newFileAction, SIGNAL(triggered()), this, SLOT(newFileFromPos()));
    QObject::connect(newFolderAction, SIGNAL(triggered()), this, SLOT(newFolderFromPos()));
    QObject::connect(renameAction, SIGNAL(triggered()), this, SLOT(renameElementFromPos()));
}

void WorkSpaceTree::openFileFromPos(){
    this->getFilePath(clickedIndex);
}

void WorkSpaceTree::renameElementFromPos(){
    bool ok = false;
    QString newName = QInputDialog::getText(this, "File name", "Type the new name of the file :", QLineEdit::Normal, QString(), &ok);
    if(ok && !newName.isEmpty()){
        if(wsController->renameFile(clickedIndex, newName.toStdString()) != 0){
            QMessageBox::warning(this, "Renaming File Error", "Names is incorrect or a file with this name already exists");
        } else {

        }
    }
}

void WorkSpaceTree::copyFileFromPos(){
    selectionStatus = COPY_ID;
    indexFileToCopy = clickedIndex;
}

void WorkSpaceTree::cutFileFromPos(){
    selectionStatus = CUT_ID;
    indexFileToCopy = clickedIndex;
}

void WorkSpaceTree::pasteFileFromPos(){
    if(selectionStatus == COPY_ID){
        string contentToCopy = wsController->getContentFromIndex(indexFileToCopy);
        if(wsController->newFile(clickedIndex, wsController->getNameFromIndex(indexFileToCopy), contentToCopy) == -1){
            QMessageBox::warning(this, "Adding File Error", "A file with this name already exists!");
        }
    } else if(selectionStatus == CUT_ID){
        string contentToCopy = wsController->getContentFromIndex(indexFileToCopy);
        if(wsController->newFile(clickedIndex, wsController->getNameFromIndex(indexFileToCopy), contentToCopy) == -1){
            QMessageBox::warning(this, "Adding File Error", "A file with this name already exists!");
        } else {
            wsController->deleteFile(indexFileToCopy);
            selectionStatus = NIL_ID;
        }
    }
}

void WorkSpaceTree::newFileFromPos(){
    bool ok = false;
    QString fileName = QInputDialog::getText(this, "File name", "Type the name of your file :", QLineEdit::Normal, QString(), &ok);
    if(ok && !fileName.isEmpty()){
        if(wsController->newFile(clickedIndex, fileName.toStdString()) == -1){
            QMessageBox::warning(this, "Adding File Error", "This name is already taken by a file!");
        }
    }
}
void WorkSpaceTree::newProject(){
    bool ok = false;
    if (workSpaceEtablished){
        QString projectName = QInputDialog::getText(this, "Project name", "Type the name of your project :", QLineEdit::Normal, QString(), &ok);
        if(ok && !projectName.isEmpty()){
            if(wsController->newProject(projectName.toStdString())){
                QMessageBox::warning(this, "Adding Project Error", "This name is already taken by a file!");
            }
        }
    }
    else{
        QMessageBox::warning(this, "Adding Project Error", "Please select a workspace before creating new project.");
    }
}

void WorkSpaceTree::newFolderFromPos(){
    bool ok = false;
    QString folderName = QInputDialog::getText(this, "Folder name", "Type the name of your folder :", QLineEdit::Normal, QString(), &ok);
    if(ok && !folderName.isEmpty()){
        if(wsController->newFolder(clickedIndex, folderName.toStdString()) == -1){
            QMessageBox::warning(this, "Adding Folder Error", "This name is already taken by a file!");
        }
    }
}


void WorkSpaceTree::selectWorkSpace(string path){
    wsController->setWorkSpace(path);
    workSpaceEtablished = true;
}

void WorkSpaceTree::mousePressEvent(QMouseEvent * e){
     if(e->button() == Qt::RightButton){ // Si clic droit
            clickedIndex = indexAt(e->pos());
            if (clickedIndex.row() != -1){ // Si on clique sur un élément
                int type = wsController->getElementType(clickedIndex);
                if (type == FILE_TYPE){
                    fileMenu->move(cursor().pos());
                    fileMenu->show();
                }
                else if(type == FOLDER_TYPE || type == PROJECT_TYPE){
                    folderMenu->move(cursor().pos());
                    folderMenu->show();
                }
            }
     }
     QTreeView::mousePressEvent(e);
}

void WorkSpaceTree::getFilePath(const QModelIndex &index){
    emit fileOpened(QString(wsController->getFilePath(index).c_str()));
}

void WorkSpaceTree::deleteFileFromPos(){
    wsController->deleteFile(clickedIndex);
}

void WorkSpaceTree::setWSModel(){
    model = wsController->getQItemModel();
    this->setModel(model);
}
