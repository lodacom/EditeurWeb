/*
 * Auteur : Abdelhamid
 * Description : couleurs et formats à appliquer au code JavaScript.
 */

#ifndef JavaScriptHighlighter_h
#define JavaScriptHighlighter_h

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>

#include "../Models/JavaScriptData.h"

#define DEFAULT_STATE 0     // L'état par défaut.
#define IN_COMMENT_STATE 1  // En commentaires multilignes.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class JavaScriptHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    JavaScriptHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

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
