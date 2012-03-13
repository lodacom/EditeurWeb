#ifndef PROJECT_H
#define PROJECT_H
#include <vector>
#include "Folder.h"
#include "File.h"
class Project : public virtual Folder{
public:
    //Constructeur Destructeur
    Project(string name = "", string parentPath = "");
    virtual ~Project();
    //Méthodes
private:
    //Attributs
    File projectFile;
};

#endif // PROJECT_H
