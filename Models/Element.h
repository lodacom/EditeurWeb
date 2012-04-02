#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <QStandardItem>
#include <algorithm>
#include <QIcon>
#include <fstream>
#define ELEMENT_TYPE 0
#define FILE_TYPE 1
#define FOLDER_TYPE 2
#define PROJECT_TYPE 3
#define WORKSPACE_TYPE 4
using namespace std;

class Element{
//Opérateur permettant le tri. 

friend bool operator < (const Element & lElem, const Element & rElem)
{
    //Création de variables temporaires, nécessaire pour le tri par ordre aplhabétique
    string temp1 = lElem.name;
    string temp2 = rElem.name;
    //On "transforme" les noms des éléments de l'arborescence en minuscules, pour la comparaison
    //Il s'agit d'un parcours de string transformant caractère par caractère
    transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
    transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
    return (temp1 < temp2 ? true : false);
}
public:
    //Constructeur Destructeur
    Element(string name = "", string parentPath = "");
    virtual ~Element();
    //Accesseurs
    virtual string getName();
    virtual void setName(string name);
    virtual string getParentPath();
    virtual void setParentPath(string parentPath);
    virtual QStandardItem* getQItem(int i = 0);
    //Méthodes
    virtual string getPath();//Retourne le chemin de l'élément
    virtual void output(int prof);//Méthode pour le debuggage
    virtual Element* getElement(list<int>* accessList);//retourne l'élément souhaité à partir d'une liste d'entier
    virtual int getType();//retourne une constante permettant de reconnaitre le type de l'objet instancié
    virtual void deleteElement();//efface physiquement et visuellement l'élément
    virtual void dropElement(int i); //
    virtual int newFile(string fileName);
    virtual int newFolder(string fileName);
    virtual int renameFile(string newName);
    virtual int renameElement(int elementPosition, string newName);
    virtual void sort();
    virtual void setQItemName(string newName);
protected:
    //Attributs
    string parentPath;//Chemin du dossier parent
    string name;//Nom de l'élément
    Element *parent;
    QStandardItem *qItem;
};

#endif // ELEMENT_H
