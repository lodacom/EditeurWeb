#include "WorkSpaceTree.h"

WorkSpaceTree::WorkSpaceTree(){
    wsController = new WorkSpaceTreeController();
    model = wsController->getQItemModel();
    this->setupMenu();
    this->setModel(model);
    this->setEditTriggers(NoEditTriggers);
    this->setExpandsOnDoubleClick(true);
    //Drag n Drop
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setDragEnabled(true);
    this->setDropIndicatorShown(true);
    this->setAcceptDrops(true);
    //
    setContextMenuPolicy(Qt::CustomContextMenu);
    //QObject::connect(this, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(getFilePath(const QModelIndex &)));
}

WorkSpaceTree::~WorkSpaceTree(){

}

void WorkSpaceTree::setupMenu(){
    menu = new QMenu(this);
    QAction* deleteAction = new QAction(tr("&Delete"),this);
    QAction* renameAction = new QAction(tr("&Rename"),this);
    menu->addAction(deleteAction);
    menu->addAction(renameAction);
    QObject::connect(deleteAction, SIGNAL(triggered()), this ,SLOT(deleteFileFromPos()));
}

void WorkSpaceTree::selectWorkSpace(string path){
    wsController->setWorkSpace(path);
}

void WorkSpaceTree::mousePressEvent(QMouseEvent * e){
     if(e->button() == Qt::RightButton){ // Si clic droit
            clickedIndex = indexAt(e->pos());
            if (clickedIndex.row() != -1){ // Si on clique sur un élément
                menu->move(cursor().pos());
                menu->show();
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

void WorkSpaceTree::dragLeaveEvent(QDragLeaveEvent * event){
    cout << "DRAG LEAVE ! " << endl;
}
void WorkSpaceTree::dragMoveEvent(QDragMoveEvent * event){
    cout << "DRAG MOVE ! " << endl;
}
void WorkSpaceTree::dropEvent(QDropEvent * event){
    cout << "DROP ! " << endl;
}
