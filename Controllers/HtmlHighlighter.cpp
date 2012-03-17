/*
 * Auteur : Abdelhamid
 * Description : configuration des formats, chaque type de mot reconnaissable
 * aura son propre format (format mot-clé, format commentaire, ...).
 */

#include "HtmlHighlighter.h"

HtmlHighlighter::HtmlHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    // Les nombres.
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::darkBlue);
    addRule(HtmlData::numberRegex, numberFormat);

    // Les balises.
    tagsFormat.setForeground(Qt::lightGray);
    tagsFormat.setFontWeight(QFont::Bold);

    addRule(HtmlData::tagOpenBeginRegex, tagsFormat);
    addRule(HtmlData::tagOpenEndRegex, tagsFormat);
    addRule(HtmlData::tagCloseRegex, tagsFormat);
    addRule(HtmlData::singleTagCloseRegex, tagsFormat);
    addRule(HtmlData::scriptTagOpenRegex, tagsFormat);
    addRule(HtmlData::scriptTagCloseRegex, tagsFormat);
    addRule(HtmlData::styleTagOpenRegex, tagsFormat);
    addRule(HtmlData::styleTagCloseRegex, tagsFormat);

    // Les attributs d'une balise.
    tagAttributeFormat.setForeground(Qt::darkMagenta);
    tagAttributeFormat.setFontWeight(QFont::Bold);
    addRule(HtmlData::tagAttributeRegex, tagAttributeFormat);

    // Les mots spéciaux (p.ex. &nbsp;).
    specialCharFormat.setForeground(Qt::darkBlue);
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
/*
    QTextCharFormat a;
    a.setForeground(Qt::darkBlue);
    a.setFontWeight(QFont::Bold);
    addMultilineRule(HtmlData::scriptTagOpenRegex,
                     HtmlData::scriptTagCloseRegex,
                     a,
                     IN_SCRIPT_TAG_STATE);

    QTextCharFormat b;
    b.setForeground(Qt::darkGreen);
    b.setFontWeight(QFont::Bold);
    addMultilineRule(HtmlData::styleTagOpenRegex,
                     HtmlData::styleTagCloseRegex,
                     b,
                     IN_STYLE_TAG_STATE);*/
}

#include "JavaScriptHighlighter.h"
void HtmlHighlighter::highlightBlock(const QString &text)
{
}

