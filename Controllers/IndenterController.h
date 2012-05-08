/*!
  *\file IndenterController.h
  *\brief Fichier d'en-tête de la classe IndenterController
  *\author Divet
  */
#ifndef INDENTERCONTROLLER_H
#define INDENTERCONTROLLER_H
#include <QObject>
#include <QLine>
#include "Models/HtmlIndenter.h"
#include "Models/PhpIndenter.h"
#include "Models/JavaScriptIndenter.h"
#include "Models/CssIndenter.h"
#define UNKNOWN_LANGUAGE -1
#define HTML_LANGUAGE 0
#define CSS_LANGUAGE 1
#define JS_LANGUAGE 2
#define PHP_LANGUAGE 3
/*!
  *\class IndenterController
  *\brief Classe controleur présente dans les central Editor, elle fait le lien avec les différents indenteurs.
  */
class IndenterController:public QObject{
Q_OBJECT

public:
    /*!
      *\brief Constructeur
      */
    IndenterController();
    /*!
      *\brief Destructeur
      */
    virtual ~IndenterController();
    /*!
      *\brief Méthode permettant selon la ligne passée en paramètre de savoir si l'on indente ou non.
      *\param line: ligne passée en paramètre
      *\return retourne -1 si il faut enlever une tabulation sur la ligne actuelle,
      * 1 s'il faut en rajouter une à la suivante, et 0 lorsqu'on doit laissé l'indentation telle qu'elle.
      */
    virtual int indentDetermin(QString line);
    /*!
      *\brief Méthode permettant de spécifier au controleur le langage courant.
      *\param language: entier définissant le language, correspondant à une des constantes définies dans cette classe.
      */
    virtual void setLanguage(int language);
private:
    HtmlIndenter *htmlIndenter;
    PhpIndenter *phpIndenter;
    JavaScriptIndenter *javascriptIndenter;
    CssIndenter *cssIndenter;
    int currentLanguage;


};

#endif // INDENTERCONTROLLER_H
