/*!
  *\file WorkSpaceTree.h
  *\brief Fichier d'en-tête de la classe WorkSpaceTree
  *\authors Berger Divet
  */

#ifndef WORKSPACETREE_H
#define WORKSPACETREE_H
#include <QTreeView>
#include <QStandardItemModel>
#include <list>
#include <QAbstractItemView>
#include <QMenu>
#include <QMouseEvent>
#include <QInputDialog>
#include <QMessageBox>
#include "../Controllers/WorkSpaceTreeController.h"
#define COPY_ID 1
#define CUT_ID 2
#define NIL_ID 0

/*!
  *\class WorkSpaceTree
  *\brief Vue associée à l'arborescence d'espace de travail de l'utilisateur
  */
class WorkSpaceTree : public QTreeView {

    Q_OBJECT

public:
    //Constructeur, Destructeur
    WorkSpaceTree();
    virtual ~WorkSpaceTree();
    virtual void selectWorkSpace(string path);
signals:
    void fileOpened(const QString& fileName);
public slots:
    virtual void getFilePath(const QModelIndex& index);
    virtual void deleteFileFromPos();
    virtual void openFileFromPos();
    virtual void copyFileFromPos();
    virtual void newFileFromPos();
    virtual void newFolderFromPos();
    virtual void newProject();
    virtual void pasteFileFromPos();
    virtual void cutFileFromPos();
    virtual void renameElementFromPos();
    virtual void setWSModel();
    //virtual void rightClickMenu(const QPoint& pos);

private:
    void setupMenus();
    QStandardItemModel *model;
    WorkSpaceTreeController *wsController;
    QMenu *fileMenu;
    QMenu *folderMenu;
    QModelIndex clickedIndex;
    bool workSpaceEtablished;
    int selectionStatus; //Trois valeurs possibles
    QModelIndex indexFileToCopy;
protected:
    virtual void mousePressEvent(QMouseEvent * e);

};

#endif // WORKSPACETREE_H
