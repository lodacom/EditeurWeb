#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
#include <iostream>
using namespace std;

class Element{
//Opérateur permettant le tri. 
friend bool operator < (const Element & lElem, const Element & rElem)
{
	 return (lElem.name < rElem.name ? true : false);
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
    //Méthodes
    virtual string getPath();//Retourne le chemin de l'élément
    virtual void output(int prof);//Méthode pour le debuggage
protected:
    //Attributs
    string parentPath;//Chemin du dossier parent
    string name;//Nom de l'élément
};

#endif // ELEMENT_H
