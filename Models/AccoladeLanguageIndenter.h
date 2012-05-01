#ifndef ACCOLADELANGUAGEINDENTER_H
#define ACCOLADELANGUAGEINDENTER_H
#include <QString>
class AccoladeLanguageIndenter{
public:
    AccoladeLanguageIndenter();
    virtual ~AccoladeLanguageIndenter();
    virtual int indentDetermin(QString line);

private:

};
#endif // ACCOLADELANGUAGEINDENTER_H
