#ifndef PROJECT_H
#define PROJECT_H
#include "Folder.h"
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
