#include <QtGui>

#include "JavaScriptHighlighter.h"

JavaScriptHighlighter::JavaScriptHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // Les mots clé.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    rule.pattern = JavaScriptData::keywordRegex;
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    // Les mots clé de déclaration.
    keywordDeclarationFormat.setFontWeight(QFont::Bold);
    keywordDeclarationFormat.setForeground(Qt::darkMagenta);
    rule.pattern = JavaScriptData::keywordDeclarationRegex;
    rule.format = keywordDeclarationFormat;
    highlightingRules.append(rule);

    // Les mots réservés.
    keywordReservedFormat.setFontWeight(QFont::Bold);
    keywordReservedFormat.setForeground(Qt::darkYellow);
    rule.pattern = JavaScriptData::keywordReservedRegex;
    rule.format = keywordReservedFormat;
    highlightingRules.append(rule);

    // Les fonctions internes de JavaScript.
    builtInFormat.setForeground(Qt::darkYellow);
    rule.pattern = JavaScriptData::builtInRegex;
    rule.format = builtInFormat;
    highlightingRules.append(rule);

    // Les identifiants.


    // Les nombres.
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::darkBlue);
    rule.pattern = JavaScriptData::numberRegex;
    highlightingRules.append(rule);

    // Commentaire sur une seule ligne.
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = JavaScriptData::singleLineCommentRegex;
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = JavaScriptData::quotationRegex;
    rule.format = quotationFormat;
    highlightingRules.append(rule);
}

void JavaScriptHighlighter::highlightBlock(const QString &text)
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
        startIndex = JavaScriptData::multilineCommentStartRegex.indexIn(text);
    }

    while (startIndex >= 0)
    {
        int endIndex = JavaScriptData::multilineCommentEndRegex.indexIn(text, startIndex);
        int commentLength;

        if (endIndex == -1)
        {
            setCurrentBlockState(IN_COMMENT_STATE);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex + JavaScriptData::multilineCommentEndRegex.matchedLength();
        }

        setFormat(startIndex, commentLength, multilineCommentFormat);
        startIndex = JavaScriptData::multilineCommentStartRegex.indexIn(text, startIndex + commentLength);
    }
}
