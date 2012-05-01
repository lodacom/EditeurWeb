/*!
* \file Highlighter.h
* \brief Déclaration de la classe mère de coloration.
* \author Abdelhamid
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

/*!
* \struct HighlightingRule
* \brief Une simple paire d'un motif et d'un format.
* L'objectif est de pouvoir enregistrer pour chaque patron (sous forme
* d'expression régulière) un format à appliquer.
*/
struct HighlightingRule
{
    QRegExp pattern;
    QTextCharFormat format;
};

/*!
* \struct MultilineHighlightingRule
* \brief Un motif de début, un motif de fin, un format à
* appliquer à toutes les lignes entre ces motifs et un code d'état.
* Utile pour les commentaires multilignes par exemple.
*/
struct MultilineHighlightingRule
{
    QRegExp patternStart;
    QRegExp patternEnd;
    QTextCharFormat format;
    int statusCode;  // Le code d'état (DEFAULT, IN_COMMENT_STATE, etc).
};

/*!
* \class Highlighter
* \brief On travaille avec des formats, chaque type de mot reconnaissable
* aura son propre format (format mot-clé, format commentaire, ...)
*/
class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    /*!
    * \brief Constructeur
    * Création d'un colorateur syntaxique.
    * \param parent : le document textuel concerné par la coloration.
    */
    Highlighter(QTextDocument *parent = 0);

    /*!
    * \brief Ajout d'une règle de coloration
    * \param pattern : l'expression régulière de reconnaissance du mot.
    * \param format : le format à appliquer au mot reconnu.
    */
    void addRule(QRegExp pattern, QTextCharFormat format);

    /*!
    * \brief Ajout d'une règle de coloration multiligne
    * \param start : l'expression régulière de reconnaissance du début.
    * \param end : l'expression régulière de reconnaissance de fin.
    * \param format : le format à appliquer aux mots entre le début et la fin.
    * \param statusCode : le numéro d'état pour cette règle (DEFAULT_STATE par défaut).
    */
    void addMultilineRule(QRegExp start, QRegExp end, QTextCharFormat format, int statusCode);

    /*!
    * \brief Accesseur en lecture sur les règles de coloration simples.
    * \return Un vecteur contenant les règles de coloration simples.
    */
    QVector<HighlightingRule> getHighlightingRules();

    /*!
    * \brief Accesseur en écriture sur les règles de coloration simples.
    * \param hr : les nouvelles règles de coloration à appliquer.
    */
    void setHighlightingRules(QVector<HighlightingRule>);

    /*!
    * \brief Accesseur en lecture sur les règles de coloration multilignes.
    * \return un vecteur contenant les règles de coloration multilignes.
    */
    QVector<MultilineHighlightingRule> getMultilineHighlightingRules();

protected:
    /*!
    * \brief Coloration d'un bloc de texte.
    * C'est la méthode la plus importante de cette classe, elle est héritée
    * de QSyntaxHighlighter et est appelée automatiquement si besoin est.
    * Elle définit le comportement du colorateur syntaxique.
    * \param  text : le bloc de texte à formater.
    */
    void highlightBlock(const QString &text);

private:
    QVector<HighlightingRule> highlightingRules;
    QVector<MultilineHighlightingRule> multilineHighlightingRules;
};

#endif
