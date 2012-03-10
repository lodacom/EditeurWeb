#ifndef FILE_H
#define FILE_H
#include "Element.h"
class File: public virtual Element{
public:
    //Constructeur Destructeur
    File(string name = "", string parentPath = "", string extension = "");
    virtual ~File();
    //Accesseurs
    virtual string getExtension();
    virtual void setExtension(string extension);
    //Méthodes
private:
    //Attributs
    string extension;//Extension du fichier
};

#endif // FILE_H
