#ifndef WORKSPACE_H
#define WORKSPACE_H
#include "Element.h"
#include "Project.h"
class WorkSpace : public virtual Element {
public:
    //Constructeur Destructeur
    WorkSpace(string name="", string parentPath="");
    virtual ~WorkSpace();
    //Méthodes
    virtual void addProject(Project *project);
    virtual void scan();// Liste les projets du workspace
    virtual void output(int prof);// Méthode pour le debuggage
    virtual QStandardItem* getQItem();
    virtual Element* getElement(list<int> *accessList);
    virtual int getType();
    virtual void deleteElement();
    virtual void dropElement(int position);
    virtual void sort();
    virtual int findProjectPosition(string projectName);
    virtual int newProject(string projectName);
    virtual int renameElement(int elementPosition, string newName);
    virtual void clear();
private:
    //Attributs
    vector<Project> projects;//Vecteur de projets
};

#endif // WORKSPACE_H
