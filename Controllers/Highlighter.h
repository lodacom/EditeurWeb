/*
 * Auteur : Abdelhamid
 * Description : définition des attributs communs aux quatre langages.
 */

#ifndef Highlighter_h
#define Highlighter_h

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

#define DEFAULT_STATE 0     // L'état par défaut.
#define IN_COMMENT_STATE 1  // En commentaires multilignes.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

struct HighlightingRule
{
    QRegExp pattern;
    QTextCharFormat format;
};

struct MultilineHighlightingRule
{
    QRegExp patternStart;
    QRegExp patternEnd;
    QTextCharFormat format;
    int statusCode;  // Le code d'état (DEFAULT, IN_COMMENT, etc).
};

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);
    void setRule(QRegExp, QTextCharFormat);
    void setMultilineRule(QRegExp start, QRegExp end, QTextCharFormat, int statusCodes);

    QVector<HighlightingRule> getHighlightingRules();
    QVector<MultilineHighlightingRule> getMultilineHighlightingRules();

protected:
    void highlightBlock(const QString &text);
    QRegExp multilineCommentStartRegex;
    QRegExp multilineCommentEndRegex;

private:
    QVector<HighlightingRule> highlightingRules;
    QVector<MultilineHighlightingRule> multilineHighlightingRules;

    // Les quatre langages ont en communs les commentaires multiligne.
    QTextCharFormat multilineCommentFormat;
};

#endif
