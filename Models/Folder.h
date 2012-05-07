/*!
  *\file Folder.h
  *\brief Fichier d'en-tête de la classe Folder
  *\authors Berger Divet
  */

#ifndef FOLDER_H
#define FOLDER_H
#include "Element.h"
#include "File.h"

/*!
  *\class Folder
  *\brief Représente chaque dossier de l'arborescence d'espace de travail de l'utilisateur,
  * elle stocke les fichiers et dossiers qui la composent dans des vecteurs
  */
class Folder: public virtual Element{

public:
    //Constructeur Destructeur
    /*!
    * \brief Constructeur de la classe Folder
    * \param name : Nom de l'élément construit
    * \param parentPath : Chemin du parent de l'élément construit
    */
    Folder(string name = "", string parentPath = "");

    /*!
    * \brief Destructeur de la classe Folder
    */
    virtual ~Folder();

    //Méthodes
    /*!
    * \brief Pour ajouter un fichier au répertoire représenté par this
    * \param file : Pointeur sur l'objet isntance de File représentant le fichier
    */
    virtual void addFile(File *file);

    /*!
    * \brief Pour ajouter un Dossier au répertoire représenté par this
    * \param file : Pointeur sur l'objet instance de Folder représentant le dossier
    */
    virtual void addFolder(Folder *folder);

    /*!
    * \brief Pour tester si le répertoire repéré par l'objet this est vide
    * \return True si le répertoire repéré par l'objet this est vide, False sinon
    */
    virtual bool isEmpty();

    /*!
    * \brief Fonction de scan des dossiers et fichiers contenus dans le répertoire repéré par l'objet this
    */
    virtual void scan();
    virtual void output(int prof);
    virtual void sort();
    virtual void setName(string name);
    virtual void setParentPath(string parentPath);
    virtual Element* getElement(list<int>* accessList);
    virtual int getType();
    virtual QStandardItem* getQItem(int i = 0);
    virtual void deleteElement();
    virtual void dropElement(int position);
    virtual int newFile(string fileName, string content="");
    virtual int newFolder(string folderName);

    /*!
    *
    */
    virtual int findFilePosition(string fileName);
    virtual int findFolderPosition(string folderName);
    virtual int renameElement(int elementPosition, string newName);
    virtual File getFileByPosition(int position);
    virtual void clear();

protected:
    //Attributs
    vector<File> files;//Les fichiers du répertoire
    vector<Folder> folders;//Les dossiers du répertoire
};
#endif // FOLDER_H
