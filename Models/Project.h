/*!
  *\file Project.h
  *\brief Fichier d'en-tête de la classe Project
  *\authors Berger Divet
  */

#ifndef PROJECT_H
#define PROJECT_H
#include "Folder.h"

/*!
  *\class Project
  *\brief Représente les dossiers de l'arborescence d'espace de travail de l'utilisateur qui sont les racines
  *des projets en développement
  */
class Project : public virtual Folder{
public:
    //Constructeur Destructeur
    Project(string name = "", string parentPath = "");
    virtual ~Project();
    virtual int getType();
    virtual void deleteElement();
    //Méthodes
private:
    //Attributs

};

#endif // PROJECT_H
