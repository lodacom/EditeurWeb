/*!
  *\file PhpIndenter.h
  *\brief Fichier d'en-tête de la classe PhpIndenter
  *\author Divet
  */
#ifndef PHPINDENTER_H
#define PHPINDENTER_H
#include "AccoladeLanguageIndenter.h"
/*!
  *\class PhpIndenter
  *\brief Classe d'indentation, spécifique au language php.
  */
class PhpIndenter: public virtual AccoladeLanguageIndenter{
public:
    PhpIndenter();
    virtual ~PhpIndenter();
    virtual int indentDetermin(QString line);

private:

};

#endif // PHPINDENTER_H
