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
    /*!
    * \brief Constructeur de la classe WorkSpaceTree
    */
    WorkSpaceTree();
    /*!
    * \brief Destructeur de la classe WorkSpaceTree
    */
    virtual ~WorkSpaceTree();
    /*!
    * \brief méthode de sélection du workspace
    * \param path: chemin du workspace
    */
    virtual void selectWorkSpace(string path);
signals:
    /*!
    * \brief signal emis lorsque l'utilisateur à double cliqué sur un élément
    */
    void fileOpened(const QString& fileName);
public slots:
    /*!
    * \brief slot qui envoie ensuite un signal au mainWindow du fichier ouvert et de son chemin
    * \param index: l'index de l'élément double cliqué
    */
    virtual void getFilePath(const QModelIndex& index);
    /*!
    * \brief slot qui détruit l'élément
    */
    virtual void deleteFileFromPos();
    /*!
    * \brief slot ouvre l'élément double cliqué
    */
    virtual void openFileFromPos();
    /*!
    * \brief slot qui copie l'élément
    */
    virtual void copyFileFromPos();
    /*!
    * \brief slot qui crée un nouveau fichier dans le répertoire
    */
    virtual void newFileFromPos();
    /*!
    * \brief slot qui crée un nouveau répertoire dans le répertoire
    */
    virtual void newFolderFromPos();
    /*!
    * \brief slot qui crée un nouveau projet dans le workspace
    */
    virtual void newProject();
    /*!
    * \brief slot qui colle un fichier
    */
    virtual void pasteFileFromPos();
    /*!
    * \brief slot qui coupe un fichier
    */
    virtual void cutFileFromPos();
    /*!
    * \brief slot qui renomme un élément
    */
    virtual void renameElementFromPos();
    /*!
    * \brief slot qui permet d'appliquer le modèle à la vue
    */
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
