/*!
* \file CssData.h
* \brief Déclaration de la classe de données du css.
* \author Abdelhamid
* \version 0.1
*/
#ifndef CSSDATA_H
#define CSSDATA_H

#include <QRegExp>

/*!
* \class CssData
* \brief Liste d'attributs statiques référençant les mots clés
* du langage css sous forme d'expressions régulières.
*/
class CSSData
{
    public:
        static QRegExp fileExtensionRegex;
        static QRegExp keywordRegex;
        static QRegExp subclassRegex;
        static QRegExp idRegex;
        static QRegExp idclassRegex;
        static QRegExp numberRegex;
        static QRegExp quotationRegex;
        static QRegExp multilineCommentStartRegex;
        static QRegExp multilineCommentEndRegex;
        static QRegExp colorRegex;
        static QRegExp unitRegex;
};


#endif // CSSDATA_H
