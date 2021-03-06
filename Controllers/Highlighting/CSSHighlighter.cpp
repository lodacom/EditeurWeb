#include <QtGui>

#include "CSSHighlighter.h"
#include "Highlighter.h"

CSSHighlighter::CSSHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    //Les nombres
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::black);
    addRule(CSSData::numberRegex,numberFormat);

    // Unités
    unitFormat.setForeground(Qt::darkRed);
    addRule(CSSData::unitRegex,unitFormat);

    //Les mots clés.
    keywordFormat.setForeground(Qt::darkGray);
    keywordFormat.setFontWeight(QFont::Bold);
    addRule(CSSData::keywordRegex,keywordFormat);

    //Les sous-classes
    subclassFormat.setForeground(Qt::red);
    addRule(CSSData::subclassRegex,subclassFormat);

    //Les id et class personnels
    idFormat.setForeground(Qt::blue);
    idclassFormat.setForeground(Qt::darkCyan);
    addRule(CSSData::idclassRegex,idclassFormat);

    addRule(CSSData::idRegex,idFormat);

    // Les simples et doubles quotes

    quotationFormat.setForeground(Qt::darkYellow);
    addRule(CSSData::quotationRegex,quotationFormat);

    // Les couleurs
    colorFormat.setForeground(Qt::darkMagenta);
    addRule(CSSData::colorRegex,colorFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkGreen);
    addMultilineRule(CSSData::multilineCommentStartRegex,
                    CSSData::multilineCommentEndRegex,
                    multilineCommentFormat,
                    IN_COMMENT_STATE);
}
