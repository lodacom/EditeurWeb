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
}

WorkSpaceTree::~WorkSpaceTree(){

}

void WorkSpaceTree::setupMenu(){
    menu = new QMenu(this);
    QAction* deleteAction = new QAction(tr("&Delete"),this);
    menu->addAction(deleteAction);
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

string WorkSpaceTree::getFilePath(const QModelIndex &index){
    return wsController->getFilePath(index);
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
