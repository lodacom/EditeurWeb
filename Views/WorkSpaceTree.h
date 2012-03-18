#ifndef WORKSPACETREE_H
#define WORKSPACETREE_H
#include <QTreeView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <list>
#include <QAbstractItemView>
#include "../Controllers/WorkSpaceTreeController.h"

class WorkSpaceTree : public virtual QTreeView {
Q_OBJECT
public:
    //Constructeur, Destructeur
    WorkSpaceTree();
    virtual ~WorkSpaceTree();
    virtual void selectWorkSpace(string path);
public slots:
    virtual string getFilePath(list<int>* workSpacePath);
private:
    QStandardItemModel *model;
    WorkSpaceTreeController *wsController;
};

#endif // WORKSPACETREE_H
