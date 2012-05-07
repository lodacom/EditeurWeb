/*!
  *\file WorkSpace.h
  *\brief Fichier d'en-tête de la classe WorkSpaceTree
  *\authors Berger Divet
  */

#ifndef WORKSPACE_H
#define WORKSPACE_H
#include "Element.h"
#include "Project.h"

/*!
  *\class WorkSpace
  *\brief Représente l'espace de travail de l'utilisateur, elle stocke les projets en cours de développement
  *dans un vecteur
  */
class WorkSpace : public virtual Element {
public:
    /*!
    * \brief Constructeur de la classe WorkSpace
    * \param name : Nom de l'élément construit
    * \param parentPath : Chemin du parent de l'élément construit
    */
    WorkSpace(string name="", string parentPath="");

    /*!
    * \brief Destructeur de la classe WorkSpace
    */
    virtual ~WorkSpace();

    /*!
    * \brief Pour ajouter un Projet au WorkSpace représenté par this
    * \param project : Pointeur sur l'objet instance de Project représentant le dossier
    */
    virtual void addProject(Project *project);

    /*!
    * \brief Parcours récursif des dossiers du WorkSpace sélectionné, afin d'ajouter au vecteur ceux qui sont des projets
    */
    virtual void scan();
    virtual void output(int prof);

    /*!
    * \brief Accesseur permettant d'obtenir le QStandardItem du WorkSpace
    * \return un pointeur sur le QStandardItem recherché
    */
    virtual QStandardItem* getQItem();
    virtual Element* getElement(list<int> *accessList);
    virtual int getType();
    virtual void deleteElement();
    virtual void dropElement(int position);
    virtual void sort();

    /*!
    * \brief Donne la position du projet projectname dans la liste représentant les éléments
    * de la treeview
    * \param projectName : chaine de caractère représentant le nom du dossier à trouver
    * \return Un entier correspondant à la position du projet projectName dans la liste d'entiers représentant la liste des
    * positions des éléments de la treeview
    */
    virtual int findProjectPosition(string projectName);

    /*!
    * \brief Ajoute un projet au vecteur de projets du WorkSpace, tout en créant le fichier de config .pro dans le dossier
    * physique correspondant au projet
    * \param projectName : Le nom du projet à ajouter
    * \return Un entier positif dans le cas de la réussite de la création du dossier physique, un entier négatif sinon
    */
    virtual int newProject(string projectName);
    virtual int renameElement(int elementPosition, string newName);
    virtual void clear();
private:
    //Attributs
    vector<Project> projects;//Vecteur de projets
};

#endif // WORKSPACE_H
