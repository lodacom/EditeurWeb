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
    setRule(HtmlData::numberRegex, numberFormat);

    // Les balises.
    tagsFormat.setForeground(Qt::lightGray);
    tagsFormat.setFontWeight(QFont::Bold);

    setRule(HtmlData::tagOpenBeginRegex, tagsFormat);
    setRule(HtmlData::tagOpenEndRegex, tagsFormat);
    setRule(HtmlData::tagCloseRegex, tagsFormat);
    setRule(HtmlData::singleTagCloseRegex, tagsFormat);
    setRule(HtmlData::scriptTagOpenRegex, tagsFormat);
    setRule(HtmlData::scriptTagCloseRegex, tagsFormat);
    setRule(HtmlData::styleTagOpenRegex, tagsFormat);
    setRule(HtmlData::styleTagCloseRegex, tagsFormat);

    // Les attributs d'une balise.
    tagAttributeFormat.setForeground(Qt::darkMagenta);
    tagAttributeFormat.setFontWeight(QFont::Bold);
    setRule(HtmlData::tagAttributeRegex, tagAttributeFormat);

    // Les mots spéciaux (p.ex. &nbsp;).
    specialCharFormat.setForeground(Qt::darkBlue);
    specialCharFormat.setFontWeight(QFont::Bold);
    setRule(HtmlData::specialCharRegex, specialCharFormat);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    setRule(HtmlData::quotationRegex, quotationFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);
    setMultilineRule(HtmlData::multilineCommentStartRegex,
                     HtmlData::multilineCommentEndRegex,
                     multilineCommentFormat,
                     IN_COMMENT_STATE);
}
