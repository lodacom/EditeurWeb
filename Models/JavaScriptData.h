/*
 * Auteur : Abdelhamid
 * Description : liste des mots reconnaissables du JavaScript,
 * utilisable pour colorer et auto-compléter le code.
 */

#ifndef JavaScriptData_h
#define JavaScriptData_h

#include <QRegExp>

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
