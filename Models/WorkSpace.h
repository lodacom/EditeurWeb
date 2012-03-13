#ifndef WORKSPACE_H
#define WORKSPACE_H
#include <vector>
#include <dirent.h>
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
    virtual void sort();
private:
    //Attributs
    vector<Project> projects;//Vecteur de projets
};

#endif // WORKSPACE_H
