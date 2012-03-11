/*
 * Auteur : Abdelhamid
 * Description : couleurs et formats à appliquer au code Html.
 * le JavaScript et Css inclus sont pris en charge par les classes JavaScriptHighlighet et CssHighlighter.
 */

#ifndef HtmlHighlighter_h
#define HtmlHighlighter_h

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

#include "Highlighter.h"
#include "../Models/HtmlData.h"

#define IN_SCRIPT_TAG_STATE 2   // En mode JavaScript.
#define IN_STYLE_TAG_STATE 3    // En mode Css.


QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class HtmlHighlighter : public Highlighter
{
    Q_OBJECT

public:
    HtmlHighlighter(QTextDocument *parent = 0);

protected:
    //void highlightBlock(const QString &text);

private:
    QTextCharFormat numberFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat specialCharFormat;
    QTextCharFormat multilineCommentFormat;

    // Les balises ouvrantes, fermantes, script et style seront formatées à l'identique.
    QTextCharFormat tagsFormat;
    QTextCharFormat tagAttributeFormat;
};

#endif