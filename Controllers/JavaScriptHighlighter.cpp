/*
 * Auteur : Abdelhamid
 * Description : configuration des formats, chaque type de mot reconnaissable
 * aura son propre format (format mot-clé, format commentaire, ...).
 */

#include "JavaScriptHighlighter.h"

JavaScriptHighlighter::JavaScriptHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    // Les nombres.
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::darkBlue);
    setRule(JavaScriptData::numberRegex, numberFormat);

    // Les méthodes et fonctions.
    functionFormat.setFontWeight(QFont::Bold);
    setRule(JavaScriptData::functionRegex, functionFormat);

    // Les mots clé.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    setRule(JavaScriptData::keywordRegex, keywordFormat);

    // Les mots clé de déclaration.
    keywordDeclarationFormat.setFontWeight(QFont::Bold);
    keywordDeclarationFormat.setForeground(Qt::darkMagenta);
    setRule(JavaScriptData::keywordDeclarationRegex, keywordDeclarationFormat);

    // Les mots réservés.
    keywordReservedFormat.setFontWeight(QFont::Bold);
    keywordReservedFormat.setForeground(Qt::darkYellow);
    setRule(JavaScriptData::keywordReservedRegex, keywordReservedFormat);

    // Les fonctions internes de JavaScript.
    builtInFormat.setForeground(Qt::darkYellow);
    setRule(JavaScriptData::builtInRegex, builtInFormat);

    // Commentaire sur une seule ligne.
    singleLineCommentFormat.setForeground(Qt::red);
    setRule(JavaScriptData::singleLineCommentRegex, singleLineCommentFormat);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    setRule(JavaScriptData::quotationRegex, quotationFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);
    setMultilineRule(JavaScriptData::multilineCommentStartRegex,
                     JavaScriptData::multilineCommentEndRegex,
                     multilineCommentFormat,
                     IN_COMMENT_STATE);
}


