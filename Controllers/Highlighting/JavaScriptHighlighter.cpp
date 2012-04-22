#include "JavaScriptHighlighter.h"

JavaScriptHighlighter::JavaScriptHighlighter(QTextDocument *parent) : Highlighter(parent)
{
    // Les nombres.
    numberFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::darkBlue);
    addRule(JavaScriptData::numberRegex, numberFormat);

    // Les méthodes et fonctions.
    functionFormat.setFontWeight(QFont::Bold);
    addRule(JavaScriptData::functionRegex, functionFormat);

    // Les mots clé.
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    addRule(JavaScriptData::keywordRegex, keywordFormat);

    // Les mots clé de déclaration.
    keywordDeclarationFormat.setFontWeight(QFont::Bold);
    keywordDeclarationFormat.setForeground(Qt::darkMagenta);
    addRule(JavaScriptData::keywordDeclarationRegex, keywordDeclarationFormat);

    // Les mots réservés.
    keywordReservedFormat.setFontWeight(QFont::Bold);
    keywordReservedFormat.setForeground(Qt::darkYellow);
    addRule(JavaScriptData::keywordReservedRegex, keywordReservedFormat);

    // Les fonctions internes de JavaScript.
    builtInFormat.setForeground(Qt::darkYellow);
    addRule(JavaScriptData::builtInRegex, builtInFormat);

    // Commentaire sur une seule ligne.
    singleLineCommentFormat.setForeground(Qt::red);
    addRule(JavaScriptData::singleLineCommentRegex, singleLineCommentFormat);

    // Les simples et doubles quotes.
    quotationFormat.setForeground(Qt::darkGreen);
    addRule(JavaScriptData::quotationRegex, quotationFormat);

    // Commentaires multilignes.
    multilineCommentFormat.setForeground(Qt::darkRed);
    addMultilineRule(JavaScriptData::multilineCommentStartRegex,
                     JavaScriptData::multilineCommentEndRegex,
                     multilineCommentFormat,
                     IN_COMMENT_STATE);
}


