/*
 * Auteur : Abdelhamid
 * Description : configuration des formats, chaque type de mot reconnaissable
 * aura son propre format (format mot-clé, format commentaire, ...).
 */

#include "Highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{}

void Highlighter::highlightBlock(const QString &text)
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
    foreach (const MultilineHighlightingRule &rule, multilineHighlightingRules)
    {
        QRegExp startExpression(rule.patternStart);
        QRegExp endExpression(rule.patternEnd);

        int startIndex = 0;
        if (previousBlockState() != rule.statusCode)
        {
            startIndex = startExpression.indexIn(text);
        }

        while (startIndex >= 0)
        {
            int endIndex = endExpression.indexIn(text, startIndex);
            int matchLength;

            if (endIndex == -1)
            {
                setCurrentBlockState(rule.statusCode);
                matchLength = text.length() - startIndex;
            }
            else
            {
                matchLength = endIndex - startIndex + endExpression.matchedLength();
            }

            setFormat(startIndex, matchLength, rule.format);
            startIndex = rule.patternStart.indexIn(text, startIndex + matchLength);
        }
    }
}

void Highlighter::addRule(QRegExp pattern, QTextCharFormat format)
{
    HighlightingRule rule;

    rule.pattern = pattern;
    rule.format = format;

    highlightingRules.append(rule);
}

void Highlighter::addMultilineRule(QRegExp start, QRegExp end, QTextCharFormat format, int statusCode)
{
    MultilineHighlightingRule rule;

    rule.patternStart = start;
    rule.patternEnd = end;
    rule.format = format;
    rule.statusCode = statusCode;

    multilineHighlightingRules.append(rule);
}

QVector<HighlightingRule> Highlighter::getHighlightingRules()
{
    return highlightingRules;
}

void Highlighter::setHighlightingRules(QVector<HighlightingRule> hr)
{
    this->highlightingRules = hr;
}

QVector<MultilineHighlightingRule> Highlighter::getMultilineHighlightingRules()
{
    return multilineHighlightingRules;
}
