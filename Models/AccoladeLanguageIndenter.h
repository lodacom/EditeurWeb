/*!
  *\file AccoladeLanguageIndenter.h
  *\brief Fichier d'en-tête de la classe AccoladeLanguageIndenter
  *\author Divet
  */
#ifndef ACCOLADELANGUAGEINDENTER_H
#define ACCOLADELANGUAGEINDENTER_H
#include <QString>
#include "Indenter.h"
/*!
  *\class AccoladeLanguageIndenter
  *\brief Classe d'indentation, regroupant les languages à accolades.
  */
class AccoladeLanguageIndenter : public virtual Indenter{
public:
    AccoladeLanguageIndenter();
    virtual ~AccoladeLanguageIndenter();
    virtual int indentDetermin(QString line);

private:

};
#endif // ACCOLADELANGUAGEINDENTER_H
