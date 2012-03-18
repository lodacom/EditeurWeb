#ifndef WORKSPACETREECONTROLLER_H
#define WORKSPACETREECONTROLLER_H
#include <QStandardItemModel>
#include <list>
#include "../Models/WorkSpace.h"
class WorkSpaceTreeController{

public:
    WorkSpaceTreeController();
    virtual ~WorkSpaceTreeController();
    virtual QStandardItemModel* getQItemModel();
    virtual string getFilePath(list<int>* path);
    virtual void setWorkSpace(string path);
private:
    QStandardItemModel *qItemModel;
    WorkSpace *workSpace;
};

#endif // WORKSPACETREECONTROLLER_H
