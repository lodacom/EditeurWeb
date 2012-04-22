#ifndef FOLDER_H
#define FOLDER_H
#include "Element.h"
#include "File.h"
class Folder: public virtual Element{

public:
    //Constructeur Destructeur
    Folder(string name = "", string parentPath = "");
    virtual ~Folder();
    //Méthodes
    virtual void addFile(File *file);//Ajoute un fichier au repertoire
    virtual void addFolder(Folder *folder);//Ajoute un dossier au repertoire
    virtual bool isEmpty();//Retourne vrai si le repertoire est vide, faux sinon
    virtual void scan();//Scanne les dossiers et fichiers du repertoire
    virtual void output(int prof);//Fonction de debbugage
    virtual void sort();//Fonction qui tri dans l'ordre alphabétique les dossiers et fichiers
    virtual void setName(string name);
    virtual void setParentPath(string parentPath);
    virtual Element* getElement(list<int>* accessList);
    virtual int getType();
    virtual QStandardItem* getQItem(int i = 0);
    virtual void deleteElement();
    virtual void dropElement(int position);
    virtual int newFile(string fileName, string content="");
    virtual int newFolder(string folderName);
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
