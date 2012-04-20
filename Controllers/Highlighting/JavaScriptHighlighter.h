/*!
* \file JavaScriptHighlighter.h
* \brief classe de coloration du langage JavaScript.
* \author Abdelhamid
* \version 0.1
*/

#ifndef JavaScriptHighlighter_h
#define JavaScriptHighlighter_h

#include "../../Models/JavaScriptData.h"
#include "Highlighter.h"

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

/*!
* \class JavaScriptHighlighter
* \brief Hérite des méthodes de la classe Highlighter,
* cette classe se résume à une classe de paramétrage pour
* spécialiser la coloration au JavaScript.
*/
class JavaScriptHighlighter : public Highlighter
{
    Q_OBJECT

public:
    /*!
    * \brief Constructeur
    * Création d'un colorateur syntaxique pour le JavaScript.
    * \param parent : le document textuel concerné par la coloration.
    */
    JavaScriptHighlighter(QTextDocument *parent = 0);

private:
    QTextCharFormat functionFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat keywordDeclarationFormat;
    QTextCharFormat keywordReservedFormat;
    QTextCharFormat builtInFormat;
    QTextCharFormat idFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat multilineCommentFormat;
    QTextCharFormat singleLineCommentFormat;
};

#endif
