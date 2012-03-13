#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <QStandardItem>
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
    virtual void setName(string parentPath);
    virtual string getParentPath();
    virtual void setParentPath(string parentPath);
    virtual QStandardItem* getQItem();
    //Méthodes
    virtual string getPath();//Retourne le chemin de l'élément
    virtual void output(int prof);//Méthode pour le debuggage
protected:
    //Attributs
    string parentPath;//Chemin du dossier parent
    string name;//Nom de l'élément
    QStandardItem *qItem;
};

#endif // ELEMENT_H
