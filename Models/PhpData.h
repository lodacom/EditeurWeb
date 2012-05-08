/*!
* \file HtmlData.h
* \brief Déclaration de la classe de données du php.
* \author Abdelhamid
* \version 0.1
*/

#ifndef PhpData_h
#define PhpData_h

#include <QRegExp>
/*!
* \class PhpData
* \brief Liste d'attributs statiques référençant les mots clés
* du langage php sous forme d'expressions régulières.
*/
class PhpData
{
    public:
        static QRegExp fileExtensionRegex;
        static QRegExp keywordRegex;
        static QRegExp keywordConstantRegex;
        static QRegExp numberRegex;
        static QRegExp quotationRegex;
        static QRegExp idRegex;
        static QRegExp multilineCommentStartRegex;
        static QRegExp multilineCommentEndRegex;
        static QRegExp singleLineCommentRegex;
        static QRegExp functionRegex;
        static QRegExp startPhpRegex;
        static QRegExp endPhpRegex;
};


#endif
