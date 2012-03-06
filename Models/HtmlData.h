/*
 * Commentaires ici.
 */

#ifndef Html_h
#define Html_h

#include <QRegExp>

class HtmlData
{
    public:
        // Pour reconnaitre les fichiers.
        static QRegExp fileExtensionRegex;

        // Pour le langage.
        static QRegExp numberRegex;
        static QRegExp quotationRegex;
        static QRegExp specialCharRegex;

        // États spéciaux.
        // Commentaires multilignes.
        static QRegExp multilineCommentStartRegex;
        static QRegExp multilineCommentEndRegex;

        // JavaScript inclus.
        static QRegExp scriptTagOpenRegex;
        static QRegExp scriptTagCloseRegex;

        // Css inclus.
        static QRegExp styleTagOpenRegex;
        static QRegExp styleTagCloseRegex;

        // Balises ouvrantes et fermantes.
        static QRegExp tagOpenRegex;
        static QRegExp tagCloseRegex;

        // Attributs d'une balise.
        static QRegExp tagAttributeRegex;
};

#endif
