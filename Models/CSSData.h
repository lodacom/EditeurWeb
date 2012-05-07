#ifndef CSSDATA_H
#define CSSDATA_H

#include <QRegExp>

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
