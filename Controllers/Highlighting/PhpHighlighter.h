/*!
* \file PhpHighlighter.h
* \brief déclaration de la classe PHP pour la coloration
* \author Pierre
* \version 0.1
*/

#ifndef PhpHighlighter_h
#define PhpHighlighter_h

#include "Highlighter.h"
#include "../../Models/PhpData.h"

#define DEFAULT_STATE 0     // L'état par défaut.
#define IN_COMMENT_STATE 1  // En commentaires multilignes.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

/*!
* \class PhpHighlighter
* \brief Hérite des méthodes de la classe Highlighter,
* classe de paramétrage pour spécialiser la coloration du PHP
*/

class PhpHighlighter : public Highlighter
{
    Q_OBJECT

public:
    /*!
    * \brief Constructeur
    * Création d'un colorateur syntaxique pour le PHP.
    * \param parent : le document textuel concerné par la coloration.
    */
    PhpHighlighter(QTextDocument *parent = 0);

private:
    QTextCharFormat keywordFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat keywordConstantFormat;
    QTextCharFormat idFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat multilineCommentFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat startPhpFormat;
    QTextCharFormat endPhpFormat;
};

#endif
