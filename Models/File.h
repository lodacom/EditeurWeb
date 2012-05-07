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
    /*!
    * \brief Constructeur de la classe File
    * \param name : Nom de l'élément construit
    * \param parentPath : Chemin du parent de l'élément construit
    */
    File(string name = "", string parentPath = "");

    /*!
    * \brief Destructeur de la classe File
    */
    virtual ~File();
    //Accesseurs

    /*!
    * \brief Accesseur permettant d'obtenir l'extension du fichier
    * \return Une string content l'extension du fichier
    */
    virtual string getExtension();
    //Méthodes
    virtual int getType();
private:
    //Attributs

};

#endif // FILE_H
