/*!
* \file JavaScriptData.h
* \brief déclaration de la classe de données du JavaScript.
* \author Abdelhamid
* \version 0.1
*/

#ifndef JavaScriptData_h
#define JavaScriptData_h

#include <QRegExp>

/*!
* \class JavaScriptData
* \brief Liste d'attributs statiques référençant les mots clés
* du langage JavaScript sous forme d'expressions régulières.
*/
class JavaScriptData
{
    public:
        // Pour reconnaître les fichiers.
        static QRegExp fileExtensionRegex;

        // Pour le langage.
        static QRegExp functionRegex;
        static QRegExp keywordRegex;
        static QRegExp keywordDeclarationRegex;
        static QRegExp keywordReservedRegex;
        static QRegExp builtInRegex;
        static QRegExp idRegex;
        static QRegExp numberRegex;
        static QRegExp quotationRegex;
        static QRegExp singleLineCommentRegex;

        // États spéciaux.
        // Commentaires multilignes.
        static QRegExp multilineCommentStartRegex;
        static QRegExp multilineCommentEndRegex;
};


#endif
