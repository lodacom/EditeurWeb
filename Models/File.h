/*!
  *\file File.h
  *\brief Fichier d'en-tête de la classe File
  *\authors Berger Divet
  */

#ifndef FILE_H
#define FILE_H
#include "Element.h"

/*!
  *\class File
  *\brief Représente chaque fichier de l'arborescence d'espace de travail de l'utilisateur
  */
class File: public virtual Element{

public:
    //Constructeur Destructeur
    File(string name = "", string parentPath = "");
    virtual ~File();
    //Accesseurs
    virtual string getExtension();
    //Méthodes
    virtual int getType();
private:
    //Attributs

};

#endif // FILE_H
