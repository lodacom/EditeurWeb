/*
 * Auteur : Pierre
 * Description : configuration des formats, chaque type de mot reconnaissable
 * aura son propre format (format mot-clé, format commentaire, ...).
 */

#include "PhpHighlighter.h"
//#include "HtmlHighlighterh"
PhpHighlighter::PhpHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    // Les mots clé.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    addRule(PhpData::keywordRegex, keywordFormat);


    // Pour les déclarations de variable

    idFormat.setForeground(Qt::gray);
    idFormat.setFontWeight(QFont::Bold);
    addRule(PhpData::idRegex, idFormat);

    // Les mots clé de déclaration.
    keywordConstantFormat.setFontWeight(QFont::Bold);
    keywordConstantFormat.setForeground(Qt::darkMagenta);
    addRule(PhpData::keywordConstantRegex, keywordConstantFormat);

    // Les nombres.
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::darkBlue);
    addRule(PhpData::numberRegex, numberFormat);

    // Commentaire sur une seule ligne.
    singleLineCommentFormat.setForeground(Qt::red);
    addRule(PhpData::singleLineCommentRegex, singleLineCommentFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);
    addMultilineRule(PhpData::multilineCommentStartRegex,
                     PhpData::multilineCommentEndRegex,
                     multilineCommentFormat,
                     IN_COMMENT_STATE);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    addRule(PhpData::quotationRegex, quotationFormat);

    // Les déclarations de fonction
    functionFormat.setForeground(Qt::darkGreen);
    addRule(PhpData::functionRegex, functionFormat);

    // Coloration balise php
    startPhpFormat.setForeground(Qt::red);
    addRule(PhpData::startPhpRegex, startPhpFormat);

    endPhpFormat.setForeground(Qt::red);
    addRule(PhpData::endPhpRegex, endPhpFormat);
}
