/*
 * Auteur : Abdelhamid
 * Description : couleurs et formats à appliquer au code JavaScript.
 */

#ifndef JavaScriptHighlighter_h
#define JavaScriptHighlighter_h

#include "../Models/JavaScriptData.h"
#include "Highlighter.h"

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class JavaScriptHighlighter : public Highlighter
{
    Q_OBJECT

public:
    JavaScriptHighlighter(QTextDocument *parent = 0);

private:
    QTextCharFormat functionFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat keywordDeclarationFormat;
    QTextCharFormat keywordReservedFormat;
    QTextCharFormat builtInFormat;
    QTextCharFormat idFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat multilineCommentFormat;
    QTextCharFormat singleLineCommentFormat;
};

#endif
