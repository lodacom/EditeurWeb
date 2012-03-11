#include <QtGui>

#include "CSSHighlighter.h"
#include "Highlighter.h"

CSSHighlighter::CSSHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    //Les mots clés.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    setRule(CSSData::keywordRegex,keywordFormat);

    //Les sous-classes
    subclassFormat.setForeground(Qt::darkMagenta);
    subclassFormat.setFontWeight(QFont::Bold);
    setRule(CSSData::subclassRegex,subclassFormat);

    //Les id et class personnels
    idFormat.setForeground(Qt::darkGray);
    idclassFormat.setForeground(Qt::darkGreen);
    setRule(CSSData::idclassRegex,idclassFormat);

    setRule(CSSData::idRegex,idFormat);

    //Les nombres
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::yellow);
    setRule(CSSData::numberRegex,numberFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);    
    setMultilineRule(CSSData::multilineCommentStartRegex,
                    CSSData::multilineCommentEndRegex,
                    multilineCommentFormat,
                    IN_COMMENT_STATE);
}
