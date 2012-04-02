#ifndef FILE_H
#define FILE_H
#include "Element.h"
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
    string extension;//Extension du fichier
};

#endif // FILE_H
