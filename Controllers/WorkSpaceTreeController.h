#ifndef WORKSPACETREECONTROLLER_H
#define WORKSPACETREECONTROLLER_H
#include <QStandardItemModel>
#include <list>
#include <pthread.h>
#include "../Models/WorkSpace.h"
class WorkSpaceTreeController{

public:
    WorkSpaceTreeController();
    virtual ~WorkSpaceTreeController();
    virtual QStandardItemModel* getQItemModel();
    virtual string getFilePath(const QModelIndex& index);
    virtual void setWorkSpace(string path);
    virtual void deleteFile(const QModelIndex& index);
private:
    virtual list<int>* indexToList(const QModelIndex& index);
    QStandardItemModel *qItemModel;
    WorkSpace *workSpace;
};

#endif // WORKSPACETREECONTROLLER_H
