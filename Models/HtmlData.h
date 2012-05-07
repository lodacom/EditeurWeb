/*!
* \file HtmlData.h
* \brief déclaration de la classe de données du html.
* \author Abdelhamid
* \version 0.1
*/
#ifndef Html_h
#define Html_h

#include <QRegExp>

/*!
* \class HtmlData
* \brief Liste d'attributs statiques référençant les mots clés
* du langage html sous forme d'expressions régulières.
*/
class HtmlData
{
    public:
        // Pour reconnaitre les fichiers.
        static QRegExp fileExtensionRegex;

        // Pour le langage.
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
        static QRegExp tagOpenBeginRegex;
        static QRegExp tagOpenEndRegex;
        static QRegExp tagCloseRegex;
        static QRegExp singleTagCloseRegex;

        // Attributs d'une balise.
        static QRegExp tagAttributeRegex;
};

#endif
