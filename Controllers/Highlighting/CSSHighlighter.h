/*!
* \file CSSHighlighter.h
* \brief déclaration de la classe CSS pour la coloration
* \author Olivier
* \version 0.1
*/

#ifndef CSSHIGHLIGHTER_H
#define CSSHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>

#include "../../Models/CSSData.h"
#include "Highlighter.h"

#define DEFAULT_STATE 0     // L'état par défaut.
#define IN_COMMENT_STATE 1  // En commentaires multilignes.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

/*!
* \class CSSHighlighter
* \brief Hérite des méthodes de la classe Highlighter,
* classe de paramétrage pour spécialiser la coloration du CSS
*/

class CSSHighlighter : public Highlighter
{
    Q_OBJECT

public:
    /*!
    * \brief Constructeur
    * Création d'un colorateur syntaxique pour le CSS.
    * \param parent : le document textuel concerné par la coloration.
    */
    CSSHighlighter(QTextDocument *parent = 0);

protected:
    //void highlightBlock(const QString &text);

private:
    QTextCharFormat fileExtensionFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat subclassFormat;
    QTextCharFormat idFormat;
    QTextCharFormat idclassFormat;
    QTextCharFormat numberFormat;

    QTextCharFormat multilineCommentFormat;
};
#endif // CSSHIGHLIGHTER_H
