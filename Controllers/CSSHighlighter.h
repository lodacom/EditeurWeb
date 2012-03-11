#ifndef CSSHIGHLIGHTER_H
#define CSSHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>

#include "../Models/CSSData.h"
#include "Highlighter.h"

#define DEFAULT_STATE 0     // L'état par défaut.
#define IN_COMMENT_STATE 1  // En commentaires multilignes.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class CSSHighlighter : public Highlighter
{
    Q_OBJECT

public:
    CSSHighlighter(QTextDocument *parent = 0);

protected:
    //void highlightBlock(const QString &text);

private:
    QTextCharFormat fileExtensionFormat;
    QTextCharFormat keywordFormat;
    QTextCharFormat subclassFormat;
    QTextCharFormat idFormat;
    QTextCharFormat idclassFormat;
    QTextCharFormat numberFormat;

    QTextCharFormat multilineCommentFormat;
};
#endif // CSSHIGHLIGHTER_H
