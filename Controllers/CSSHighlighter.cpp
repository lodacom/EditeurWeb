#include <QtGui>

#include "CSSHighlighter.h"
#include "Highlighter.h"

CSSHighlighter::CSSHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    //Les mots clés.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    addRule(CSSData::keywordRegex,keywordFormat);

    //Les sous-classes
    subclassFormat.setForeground(Qt::darkMagenta);
    subclassFormat.setFontWeight(QFont::Bold);
    addRule(CSSData::subclassRegex,subclassFormat);

    //Les id et class personnels
    idFormat.setForeground(Qt::darkGray);
    idclassFormat.setForeground(Qt::darkGreen);
    addRule(CSSData::idclassRegex,idclassFormat);

    addRule(CSSData::idRegex,idFormat);

    //Les nombres
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::yellow);
    addRule(CSSData::numberRegex,numberFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);
    setMultilineRule(CSSData::multilineCommentStartRegex,
                    CSSData::multilineCommentEndRegex,
                    multilineCommentFormat,
                    IN_COMMENT_STATE);
}
