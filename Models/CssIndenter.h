/*!
  *\file CssIndenter.h
  *\brief Fichier d'en-tête de la classe CssIndenter
  *\author Olivier Pierre
  */
#ifndef CSSINDENTER_H
#define CSSINDENTER_H
#include "AccoladeLanguageIndenter.h"
/*!
  *\class CssIndenter
  *\brief Classe d'indentation, spécifique au language css.
  */
class CssIndenter: public virtual AccoladeLanguageIndenter{
public:
    CssIndenter();
    virtual ~CssIndenter();
    virtual int indentDetermin(QString line);
};
#endif // CSSINDENTER_H
