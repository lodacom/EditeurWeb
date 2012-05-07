#include "HtmlHighlighter.h"

HtmlHighlighter::HtmlHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    // Les balises.
    tagsFormat.setForeground(Qt::blue);

    addRule(HtmlData::tagOpenBeginRegex, tagsFormat);
    addRule(HtmlData::tagOpenEndRegex, tagsFormat);
    addRule(HtmlData::tagCloseRegex, tagsFormat);
    addRule(HtmlData::singleTagCloseRegex, tagsFormat);
    addRule(HtmlData::scriptTagOpenRegex, tagsFormat);
    addRule(HtmlData::scriptTagCloseRegex, tagsFormat);
    addRule(HtmlData::styleTagOpenRegex, tagsFormat);
    addRule(HtmlData::styleTagCloseRegex, tagsFormat);

    // Les attributs d'une balise.
    tagAttributeFormat.setForeground(Qt::red);
    addRule(HtmlData::tagAttributeRegex, tagAttributeFormat);

    // Les mots spéciaux (p.ex. &nbsp;).
    specialCharFormat.setForeground(Qt::darkCyan);
    specialCharFormat.setFontWeight(QFont::Bold);
    addRule(HtmlData::specialCharRegex, specialCharFormat);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    addRule(HtmlData::quotationRegex, quotationFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);
    addMultilineRule(HtmlData::multilineCommentStartRegex,
                     HtmlData::multilineCommentEndRegex,
                     multilineCommentFormat,
                     IN_COMMENT_STATE);

    // Le JavaScript inclus.
    SpecialMode mode;
    mode.patternStart = HtmlData::scriptTagOpenRegex;
    mode.patternEnd = HtmlData::scriptTagCloseRegex;
    mode.statusCode = IN_SCRIPT_TAG_STATE;
    JavaScriptHighlighter j;
    mode.format = j.getHighlightingRules();
    mode.multilineFormat = j.getMultilineHighlightingRules();

    specialModes.append(mode);

    // Le Css inclus.
    mode.patternStart = HtmlData::styleTagOpenRegex;
    mode.patternEnd = HtmlData::styleTagCloseRegex;
    mode.statusCode = IN_STYLE_TAG_STATE;
    CSSHighlighter c;
    mode.format = c.getHighlightingRules();
    mode.multilineFormat = c.getMultilineHighlightingRules();

    specialModes.append(mode);
}

void HtmlHighlighter::highlightBlock(const QString &text)
{
    Highlighter::highlightBlock(text);

    foreach (const SpecialMode &mode, specialModes)
    {
        QRegExp startExpression(mode.patternStart);
        QRegExp endExpression(mode.patternEnd);

        int startIndex = 0;
        if (previousBlockState() != mode.statusCode)
        {
            startIndex = startExpression.indexIn(text);
        }

        while (startIndex >= 0)
        {
            int endIndex = endExpression.indexIn(text, startIndex);
            int matchLength;

            if (endIndex == -1)
            {
                setCurrentBlockState(mode.statusCode);
                matchLength = text.length() - startIndex;
            }
            else
            {
                matchLength = endIndex - startIndex + endExpression.matchedLength();
            }

            setFormat(text, startIndex, matchLength, mode.format, mode.multilineFormat);
            startIndex = mode.patternStart.indexIn(text, startIndex + matchLength);
        }
    }

}

void HtmlHighlighter::setFormat(const QString &text, int start, int count,
                                const QVector<HighlightingRule> &format,
                                const QVector<MultilineHighlightingRule> &multilineFormat)
{
    foreach (const HighlightingRule &rule, format)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= start and index <= start+count)
        {
            int length = expression.matchedLength();
            Highlighter::setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
}
