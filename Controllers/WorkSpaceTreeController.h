#ifndef WORKSPACETREECONTROLLER_H
#define WORKSPACETREECONTROLLER_H
#include <QStandardItemModel>
#include "../Models/WorkSpace.h"
class WorkSpaceTreeController{

public:
    WorkSpaceTreeController();
    virtual ~WorkSpaceTreeController();
    virtual QStandardItemModel* getQItemModel();
private:
    QStandardItemModel *qItemModel;
    WorkSpace *workSpace;
};

#endif // WORKSPACETREECONTROLLER_H
