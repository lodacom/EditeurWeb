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
    virtual File* getFile(list<int>* path);
    virtual QStandardItem* getQItem();
protected:
    //Attributs
    vector<File> files;//Les fichiers du répertoire
    vector<Folder> folders;//Les dossiers du répertoire
};
#endif // FOLDER_H
