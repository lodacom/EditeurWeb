/*
 * Commentaires ici.
 */

#ifndef PhpData_h
#define PhpData_h

#include <QRegExp>

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
