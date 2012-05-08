#ifndef INDENTER_H
#define INDENTER_H
#include <QString>
/*!
  *\class Indenter
  *\brief Classe abstraite, définissant la méthode indentDetermin commune à toutes les classes dérivant d'Indenter
  */
class Indenter{
public:
    /*!
      *\brief Constructeur
      */
    Indenter();
    /*!
      *\brief Destructeur
      */
    virtual ~Indenter();
    /*!
      *\brief Méthode permettant selon la ligne passée en paramètre de savoir si l'on indente ou non.
      *\param line: ligne passée en paramètre
      *\return retourne -1 si il faut enlever une tabulation sur la ligne actuelle,
      * 1 s'il faut en rajouter une à la suivante, et 0 lorsqu'on doit laissé l'indentation telle qu'elle.
      */
    virtual int indentDetermin(QString line) = 0;
private:

};

#endif // INDENTER_H
