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
    /*!
      *\brief Constructeur
      */
    WorkSpaceTreeController();
    /*!
      *\brief Destructeur
      */
    virtual ~WorkSpaceTreeController();
    /*!
      *\brief Retourne le QStandardItemModel associé au WorkSpace
      */
    virtual QStandardItemModel* getQItemModel();
    /*!
      *\brief Retourne le chemin du fichier pointé par l'index
      */
    virtual string getFilePath(const QModelIndex& index);
    /*!
      *\brief Retourne l'extension du fichier pointée par l'index
      */
    virtual string getFileExtension(const QModelIndex& index);
    /*!
      *\brief Retourne le type de fichier poinjté par l'index
      */
    virtual int getElementType(const QModelIndex& index);
    /*!
      *\brief Crée un nouveau fichier dans le modèle.
        * \param index: l'index du dossier parent
        * \param filename: le nom du nouveau fichier
        * \param content: le contenu du fichier
      */
    virtual int newFile(const QModelIndex& index, string fileName, string content="");
    /*!
      *\brief Crée un nouveau dossier dans le modèle.
        * \param index: l'index du dossier parent
        * \param filename: le nom du nouveau dossier
      */
    virtual int newFolder(const QModelIndex& index, string folderName);
    /*!
      *\brief Crée un nouveau projet dans le workspace.
        * \param projectName: nom du projet
      */
    virtual int newProject(string projectName);
    /*!
      *\brief établi le nouveau workspace
        * \param path: le chemin du workspace
      */
    virtual void setWorkSpace(string path);
    /*!
      *\brief Supprime le fichier pointé par l'index
      */
    virtual void deleteFile(const QModelIndex& index);
    /*!
      *\brief Retourne le nom du fichier pointé par l'index
      */
    virtual string getNameFromIndex(const QModelIndex& index);
    /*!
      *\brief Renomme l'élément pointé par l'index
        * \param newName: le nouveau nom du fichier
      */
    virtual int renameFile(const QModelIndex &index, string newName);
    /*!
      *\brief Retourne le contenu du fichier pointé par l'index
      */
    virtual string getContentFromIndex(const QModelIndex &index);
//    virtual int pasteInFolder(const QModelIndex& index, string fileName, string content);
signals:
    /*!
      *\brief Slot qui crée un nouveau workspace
      */
    void newWorkSpace();
private:
    virtual list<int>* indexToList(const QModelIndex& index);
    QStandardItemModel *qItemModel;
    WorkSpace *workSpace;
};

#endif // WORKSPACETREECONTROLLER_H
