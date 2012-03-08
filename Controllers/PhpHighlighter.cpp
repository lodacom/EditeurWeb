#include <QtGui>

#include "PhpHighlighter.h"
//#include "HtmlHighlighterh"
PhpHighlighter::PhpHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // Les mots clé.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    rule.pattern = PhpData::keywordRegex;
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    // Pour les déclarations de variable

    idFormat.setForeground(Qt::gray);
    idFormat.setFontWeight(QFont::Bold);
    rule.pattern = PhpData::idRegex;
    rule.format = idFormat;
    highlightingRules.append(rule);

    // Les mots clé de déclaration.
    keywordConstantFormat.setFontWeight(QFont::Bold);
    keywordConstantFormat.setForeground(Qt::darkMagenta);
    rule.pattern = PhpData::keywordConstantRegex;
    rule.format = keywordConstantFormat;
    highlightingRules.append(rule);

    // Les identifiants.


    // Les nombres.
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::darkBlue);
    rule.pattern = PhpData::numberRegex;
    highlightingRules.append(rule);

    // Commentaire sur une seule ligne.
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = PhpData::singleLineCommentRegex;
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = PhpData::quotationRegex;
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    // Les déclarations de fonction
    functionFormat.setForeground(Qt::darkGreen);
    rule.pattern = PhpData::functionRegex;
    rule.format = functionFormat;
    highlightingRules.append(rule);

    
    // Coloration balise php
    startPhpFormat.setForeground(Qt::red);
    rule.pattern=PhpData::startPhpRegex;
    rule.format=startPhpFormat;
    highlightingRules.append(rule);

    endPhpFormat.setForeground(Qt::red);
    rule.pattern=PhpData::endPhpRegex;
    rule.format=endPhpFormat;
    highlightingRules.append(rule);



}

void PhpHighlighter::highlightBlock(const QString &text)
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
        startIndex = PhpData::multilineCommentStartRegex.indexIn(text);
    }

    while (startIndex >= 0)
    {
        int endIndex = PhpData::multilineCommentEndRegex.indexIn(text, startIndex);
        int commentLength;

        if (endIndex == -1)
        {
            setCurrentBlockState(IN_COMMENT_STATE);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex + PhpData::multilineCommentEndRegex.matchedLength();
        }

        setFormat(startIndex, commentLength, multilineCommentFormat);
        startIndex = PhpData::multilineCommentStartRegex.indexIn(text, startIndex + commentLength);
    }
}
