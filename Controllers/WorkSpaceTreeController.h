/*!
  *\file WorkSpaceTreeController.h
  *\brief Fichier d'en-tête de la classe WorkSpaceTreeController
  *\authors Berger Divet
  */

#ifndef WORKSPACETREECONTROLLER_H
#define WORKSPACETREECONTROLLER_H
#include <QStandardItemModel>
#include <list>
#include <pthread.h>
#include "../Models/WorkSpace.h"

/*!
  *\class WorkSpaceTreeController
  *\brief Controller agissant sur la vue et le modèle de l'arborescence d'espace de travail de l'utilisateur
  */
class WorkSpaceTreeController: public QObject{
Q_OBJECT

public:
    WorkSpaceTreeController();
    virtual ~WorkSpaceTreeController();
    virtual QStandardItemModel* getQItemModel();
    virtual string getFilePath(const QModelIndex& index);
    virtual string getFileExtension(const QModelIndex& index);
    virtual int getElementType(const QModelIndex& index);
    virtual int newFile(const QModelIndex& index, string fileName, string content="");
    virtual int newFolder(const QModelIndex& index, string folderName);
    virtual int newProject(string projectName);
    virtual void setWorkSpace(string path);
    virtual void deleteFile(const QModelIndex& index);
    virtual string getNameFromIndex(const QModelIndex& index);
    virtual int renameFile(const QModelIndex &index, string newName);
    virtual string getContentFromIndex(const QModelIndex &index);
//    virtual int pasteInFolder(const QModelIndex& index, string fileName, string content);
signals:
    void newWorkSpace();
private:
    virtual list<int>* indexToList(const QModelIndex& index);
    QStandardItemModel *qItemModel;
    WorkSpace *workSpace;
};

#endif // WORKSPACETREECONTROLLER_H
