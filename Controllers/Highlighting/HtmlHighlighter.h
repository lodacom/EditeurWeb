/*!
* \file HtmlHighlighter.h
* \brief classe de coloration du langage Html.
* \author Abdelhamid
* \version 0.1
*/

#ifndef HtmlHighlighter_h
#define HtmlHighlighter_h

#include <QTextCharFormat>

#include "Highlighter.h"
#include "../../Models/HtmlData.h"

#include "JavaScriptHighlighter.h"
#include "CSSHighlighter.h"

#define IN_SCRIPT_TAG_STATE 2   // En mode JavaScript.
#define IN_STYLE_TAG_STATE 3    // En mode Css.

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

/*!
* \struct SpecialMode
* \brief Un mode spécial est un mode
* JavaScript inclus ou Css inclus. On enregistre toutes les variables
* nécessaires pour formater ces langages.
*/
struct SpecialMode
{
    QRegExp patternStart;
    QRegExp patternEnd;
    int statusCode;
    QVector<HighlightingRule> format;
    QVector<MultilineHighlightingRule> multilineFormat;
};

/*!
* \class HtmlHighlighter
* \brief Classe de coloration du langage Html. Le JavaScript inclus et le
* Css inclus sont pris en charges par les classes JavaScriptHighlighter et CssHighlighter.
*/
class HtmlHighlighter : public Highlighter
{
    Q_OBJECT

public:
    /*!
    * \brief Constructeur
    * Création d'un colorateur syntaxique pour le Html.
    * \param parent : le document textuel concerné par la coloration.
    */
    HtmlHighlighter(QTextDocument *parent = 0);

protected:
    /*!
    * \brief Coloration d'un bloc de texte.
    * Il est nécessaire de redéfinir cette méthode héritée de la classe Highlighter
    * pour prendre en charge le JavaScript ou Css éventuellement inclus.
    * \param text : le bloc de texte à formatter.
    */
    void highlightBlock(const QString &text);

private:
    /*!
    * \brief Application d'un format à un bloc de texte.
    * Appelée par la méthode highlightBlock en cas de mode spécial.
    * Concerne uniquement le JavaScript et Css inclus.
    * \param text : le bloc de texte à formatter.
    * \param start : l'indice de début de formatage.
    * \param count : la longueur de la sous-chaîne à formater.
    * \param format : les règles simples à appliquer.
    * \param multilineFormat : les règles multiligne à appliquer.
    */
    void setFormat (const QString &text, int start, int count,
                    const QVector<HighlightingRule> &format,
                    const QVector<MultilineHighlightingRule> &multilineFormat);

    QVector<SpecialMode> specialModes;

    QTextCharFormat numberFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat specialCharFormat;
    QTextCharFormat multilineCommentFormat;

    // Les balises ouvrantes, fermantes, script et style seront formatées à l'identique.
    QTextCharFormat tagsFormat;
    QTextCharFormat tagAttributeFormat;
};

#endif
