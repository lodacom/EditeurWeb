/*
 * Commentaires ici.
 */

#ifndef JavaScriptData_h
#define JavaScriptData_h

#include <QRegExp>

class JavaScriptData
{
    public:
        static QRegExp fileExtensionRegex;
        static QRegExp keywordRegex;
        static QRegExp keywordDeclarationRegex;
        static QRegExp keywordReservedRegex;
        static QRegExp builtInRegex;
        static QRegExp idRegex;
        static QRegExp numberRegex;
        static QRegExp quotationRegex;
        static QRegExp multilineCommentStartRegex;
        static QRegExp multilineCommentEndRegex;
        static QRegExp singleLineCommentRegex;
};


#endif
