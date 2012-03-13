#ifndef PhpHighlighter_h
#define PhpHighlighter_h

#include "Highlighter.h"
#include "../Models/PhpData.h"

#define DEFAULT_STATE 0     // L'état par défaut.
#define IN_COMMENT_STATE 1  // En commentaires multilignes.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class PhpHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    PhpHighlighter(QTextDocument *parent = 0);

private:
    QTextCharFormat keywordFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat keywordConstantFormat;
    QTextCharFormat idFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat multilineCommentFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat startPhpFormat;
    QTextCharFormat endPhpFormat;
};

#endif
