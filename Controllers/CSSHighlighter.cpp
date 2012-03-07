#include <QtGui>

#include "CSSHighlighter.h"

CSSHighlighter::CSSHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    //Les mots clés.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    rule.pattern=CSSData::keywordRegex;
    rule.format=keywordFormat;
    highlightingRules.append(rule);

    //Les sous-classes
    subclassFormat.setForeground(Qt::darkMagenta);
    subclassFormat.setFontWeight(QFont::Bold);
    rule.pattern=CSSData::subclassRegex;
    rule.format=subclassFormat;
    highlightingRules.append(rule);

    //Les id et class personnels
    idFormat.setForeground(Qt::darkGray);
    idclassFormat.setForeground(Qt::darkGreen);
    rule.pattern=CSSData::idclassRegex;
    rule.format=idclassFormat;
    highlightingRules.append(rule);
    rule.pattern=CSSData::idRegex;
    rule.format=idFormat;
    highlightingRules.append(rule);

    //Les nombres
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::yellow);
    rule.pattern = CSSData::numberRegex;
    rule.format=numberFormat;
    highlightingRules.append(rule);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);    

}

void CSSHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(DEFAULT_STATE);

    int startIndex = 0;
    if (previousBlockState() != IN_COMMENT_STATE)
    {
        startIndex = CSSData::multilineCommentStartRegex.indexIn(text);
    }

    while (startIndex >= 0)
    {
        int endIndex = CSSData::multilineCommentEndRegex.indexIn(text, startIndex);
        int commentLength;

        if (endIndex == -1)
        {
            setCurrentBlockState(IN_COMMENT_STATE);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex + CSSData::multilineCommentEndRegex.matchedLength();
        }

        setFormat(startIndex, commentLength, multilineCommentFormat);
        startIndex = CSSData::multilineCommentStartRegex.indexIn(text, startIndex + commentLength);
    }
}
