#include <QtGui>
#include "htmlhighlighter.h"

htmlhighlighter::htmlhighlighter(QTextDocument *parent): QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);//on met la couleur bleu foncé pour les mots clé
    keywordFormat.setFontWeight(QFont::Bold);//on les met en gras
    QStringList keywordPatterns;
    keywordPatterns  << "\\ba\\b" << "\\babbr\\b" << "\\bacronym\\b" << "\\baddress\\b" << "\\barea\\b" <<
                    "\\bb\\b" << "\\bbase\\b" << "\\bbdo\\b" << "\\bbgsound\\b" << "\\bbig\\b" <<
                   "\\bblink\\b" << "\\bblockquote\\b" << "\\bbody\\b" << "\\bbr\\b" << "\\bbutton\\b"<< "\\bcanvas\\b" <<
                    "\\bcaption\\b" << "\\bcite\\b" << "\\bcode\\b" << "\\bcol\\b" << "\\bcolgroup\\b" << "\\bcomment\\b" <<
                    "\\bdd\\b" << "\\bdel\\b" << "\\bdfn\\b" << "\\bdiv\\b" << "\\bdl\\b" << "\\bdt\\b" << "\\bem\\b" <<
                    "\\bembed\\b" << "\\bfieldset\\b" << "\\bform\\b" << "\\bframe\\b" << "\\bframeset\\b" << "\\bh1\\b" <<
                    "\\bh2\\b" << "\\bh3\\b" << "\\bh4\\b" << "\\bh5\\b" << "\\bh6\\b" << "\\bhead\\b" << "\\bhr\\b" <<
                    "\\bhtml\\b" << "\\bi\\b" << "\\biframe\\b" << "\\bilayer\\b" << "\\bimg\\b" << "\\binput\\b" <<
                    "\\bins\\b" << "\\bkbd\\b" << "\\blabel\\b" << "\\blayer\\b" << "\\blegend\\b" << "\\bli\\b" <<
                    "\\blink\\b" << "\\bmap\\b" << "\\bmarquee\\b" << "\\bmeta\\b" << "\\bmulticol\\b" << "\\bnobr\\b" <<
                     "\\bnoframes\\b" << "\\bnoscript\\b" << "\\bobject\\b" << "\\bol\\b" << "\\boptgroup\\b" << "\\boption\\b" <<
                     "\\bp\\b" << "\\bparam\\b" << "\\bpre\\b" << "\\bq\\b" << "\\bsamp\\b" << "\\bscript\\b" << "\\bselect\\b" <<
                     "\\bsmall\\b" << "\\bspan\\b" << "\\bstrong\\b" << "\\bstyle\\b" << "\\bsub\\b" << "\\bsup\\b" << "\\btable\\b" <<
                     "\\btbody\\b" << "\\btd\\b" << "\\btextarea\\b" << "\\btfoot\\b" << "\\bth\\b" << "\\bthead\\b" << "\\btitle\\b" <<
                     "\\btr\\b" << "\\btt\\b" << "\\bul\\b" << "\\bvar\\b" << "\\bwbr\\b" << "\\bxml\\b" ;

    foreach (const QString &pattern, keywordPatterns)
    {
        /*ici on les ajoute un à un grace à la boucle foreach dans le vecteur
          highlightingRules (append) on applique le format que l'on a définit plus haut*/
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    multiLineCommentFormat.setForeground(Qt::green);//on met les commentaires multilignes en cyan
    commentStartExpression = QRegExp("<!--");
    commentEndExpression = QRegExp("--!>");
}

void htmlhighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    QSyntaxHighlighter::setCurrentBlockState(0);


    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

/*ce qui est en dessous permet de reconnaître les commentaires mutilignes en javascript
  de manière plus "astucieuse" que de mettre une regexep en dure*/
    while (startIndex >= 0)
    {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

