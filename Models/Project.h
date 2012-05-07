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
    /*!
    * \brief Constructeur de la classe Project
    * \param name : Nom de l'élément construit
    * \param parentPath : Chemin du parent de l'élément construit
    */
    Project(string name = "", string parentPath = "");

    /*!
    * \brief Destructeur de la classe Project
    */
    virtual ~Project();
    virtual int getType();
    virtual void deleteElement();
    //Méthodes
private:
    //Attributs

};

#endif // PROJECT_H
