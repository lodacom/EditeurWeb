/*!
  *\file HtmlIndenter.h
  *\brief Fichier d'en-tête de la classe HtmlIndenter
  *\author Divet
  */
#ifndef HTMLINDENTER_H
#define HTMLINDENTER_H
#include <QString>
#include "Indenter.h"
/*!
  *\class HtmlIndenter
  *\brief Classe d'indentation, spécifique au language html.
  */
class HtmlIndenter: public virtual Indenter{
public:
    HtmlIndenter();
    virtual ~HtmlIndenter();
    virtual int indentDetermin(QString line);

private:

};

#endif // HTMLINDENTER_H
