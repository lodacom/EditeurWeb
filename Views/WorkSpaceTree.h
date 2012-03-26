#ifndef WORKSPACETREE_H
#define WORKSPACETREE_H
#include <QTreeView>
#include <QStandardItemModel>
#include <list>
#include <QAbstractItemView>
#include <QMenu>
#include <QMouseEvent>
#include "../Controllers/WorkSpaceTreeController.h"

class WorkSpaceTree : public QTreeView {

    Q_OBJECT

public:
    //Constructeur, Destructeur
    WorkSpaceTree();
    virtual ~WorkSpaceTree();
    virtual void selectWorkSpace(string path);

public slots:
    virtual string getFilePath(const QModelIndex& index);
    virtual void deleteFileFromPos();
    //virtual void rightClickMenu(const QPoint& pos);
private:
    QStandardItemModel *model;
    WorkSpaceTreeController *wsController;
    QMenu *menu;
    QModelIndex clickedIndex;
    void setupMenu();
protected:
    virtual void dragLeaveEvent(QDragLeaveEvent * event);
    virtual void dragMoveEvent(QDragMoveEvent * event);
    virtual void dropEvent(QDropEvent * event);
    virtual void mousePressEvent(QMouseEvent * e);

};

#endif // WORKSPACETREE_H
