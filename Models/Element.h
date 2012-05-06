/*!
  *\file Element.h
  *\brief Fichier d'en-tête de la classe Element
  *\authors Berger Divet
  */
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
#include <fcntl.h>
#include "../Tools/Tools.h"
#define ELEMENT_TYPE 0
#define FILE_TYPE 1
#define FOLDER_TYPE 2
#define PROJECT_TYPE 3
#define WORKSPACE_TYPE 4
using namespace std;

/*!
  *\class Element
  *\brief Regroupe l'ensemble des méthodes, attributs et constantes qui sont communs à
  *tous les "fils" Folder, File et Project
  */
class Element{

    /*!
    * \brief Définition d'un nouvel opérateur de comparaison entre éléments
    * \param lElem : Élément à gauche de l'opérateur
    * \param rElem : Élément à droite de l'opérateur
    * \return true si lElem est considéré inférieur (au sens alphabétique) à rElem, false sinon
    */
    friend bool operator < (const Element & lElem, const Element & rElem){
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
    /*!
    * \brief Constructeur de la classe Element
    * \param name : Nom de l'élément construit
    * \param parentPath : Chemin du parent de l'élément construit
    */
    Element(string name = "", string parentPath = "");

    /*!
    * \brief Destructeur de la classe Element
    */
    virtual ~Element();

    //Accesseurs
    /*!
    * \brief Accesseur donnant le nom de l'élément
    * \return Une string contenant le nom de l'élément this
    */
    virtual string getName();

    /*!
    * \brief Accesseur permettant de modifier le nom de l'élément
    * \param name : Le nouveau nom à donner à l'élément this
    */
    virtual void setName(string name);

    /*!
    * \brief Accesseur donnant le chemin du dossier parent de l'élément
    * \return Une string contenant le chemin du dossier parent de l'élément this
    */
    virtual string getParentPath();

    /*!
    * \brief Accesseur permettant de modifier le chemin du dossier parent de l'élément
    * \param parentPath : Le nouveau chemin vers le parent de l'élément this
    */
    virtual void setParentPath(string parentPath);

    /*!
    * \brief Accesseur permettant d'obtenir le QStandardItem d'un élément
    * \param si i = 0, on retourne le qItem lié à tous les qItem des sous éléments. Si i = 1 on retourne uniquement le qItem.
    */
    virtual QStandardItem* getQItem(int i = 0);

    //Méthodes
    /*!
    * \brief Méthode permettant d'obtenir le chemin de l'élément grâce au chemin du parent et au nom de l'élément
    * \return Le chemin vers l'élément this
    */
    virtual string getPath();

    /*!
    * \brief Méthode fournissant un affichage console, utilisée pour le déboggage de l'application
    * \param prof : Profondeur de l'affichage console
    */
    virtual void output(int prof);

    /*!
    * \brief Accesseur donnant l'élément courant à partir d'une liste d'entiers correspondant aux index des
    * éléments de l'arborescence d'espace de travail de l'utilisateur
    * \param accessList : La liste des indices de l'arborescence
    * \return Un pointeur vers l'élément this
    */
    virtual Element* getElement(list<int>* accessList);

    /*!
    * \brief Méthode permettant de savoir si l'élément est un File, un Folder, un Project ou un WorkSpace
    * \return Une constante correspondant au type de l'élément instancié
    */
    virtual int getType();

    /*!
    * \brief Méthode effaçant le fichier physique correspondant à l'élément, ainsi que l'objet this lui-même
    */
    virtual void deleteElement();

    /*!
    * \brief Méthode utilisé pour les éléments conteneurs (dossier, projet) qui applique la suppression récursive de l'élément à l'index i et de ses sous éléments
    * \param i: i est l'index de l'élément à supprimer
    */
    virtual void dropElement(int i);

    /*!
    * \brief Méthode créant un fichier physique, avec ou sans contenu, correspondant à l'élément this
    * \param fileName : Le nom du fichier qui sera créé
    * \param content : Contenu éventuel du fichier créé
    * \return Un entier positif ou nul dans le cas d'une création sans problèmes, un entier négatif
    * correspondant à une erreur sinon
    */
    virtual int newFile(string fileName, string content = "");

    /*!
    * \brief Méthode créant un dossier physique correspondant à l'élément this (dans le cas
    * ou cet élément est de type dossier)
    * \param fileName : Le nom du dossier créé
    * \return Un entier positif ou nul dans le cas d'une création sans problèmes, un entier négatif
    * correspondant à une erreur sinon
    */
    virtual int newFolder(string fileName);

    /*!
    * \brief Méthode renommant le fichier physique correspondant à l'élément this
    * \param newName : Le nouveau nom du fichier
    * \return Un entier positif ou nul dans le cas d'un renommage sans problèmes, un entier négatif
    * correspondant à une erreur sinon
    */
    virtual int renameFile(string newName);

    /*!
    * \brief permet le rafraichissement du dossier en renommant l'élément se trouvant à elementPosition
    * \param elementPosition: position de l'élément à renommer
    * \param newName: nouveau nom de l'élément
    * \return 0 si l'élément a été modifié correctement, autre sinon
    */
    virtual int renameElement(int elementPosition, string newName);

    /*!
    * \brief Fonction de tri
    */
    virtual void sort();

    /*!
    * \brief renomme le qItem de l'élément
    * \param le nouveau nom du qItem
    */
    virtual void setQItemName(string newName);

    /*!
    * \brief Accesseur donnant le contenu du fichier physique correspondant à l'élément this
    * \return Une string correspondant au contenu du fichier physique associé à l'élément this
    */
    virtual string getContent();

    /*!
    * \brief Accesseur permettant une modification du contenu du fichier physique associé à l'élément this
    * \param newContent : Le nouveau contenu du fichier associé à l'élément this
    */
    virtual void setContent(string newContent);

    /*!
    * \brief Vide pour les éléments conteneurs (dossiers, projets) tous les sous éléments.
    */
    virtual void clear();

protected:
    //Attributs
    string parentPath;//Chemin du dossier parent
    string name;//Nom de l'élément
    QStandardItem *qItem;
};

#endif // ELEMENT_H
