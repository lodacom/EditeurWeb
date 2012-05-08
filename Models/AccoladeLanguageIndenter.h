#ifndef ACCOLADELANGUAGEINDENTER_H
#define ACCOLADELANGUAGEINDENTER_H
#include <QString>
#include "Indenter.h"
class AccoladeLanguageIndenter : public virtual Indenter{
public:
    AccoladeLanguageIndenter();
    virtual ~AccoladeLanguageIndenter();
    virtual int indentDetermin(QString line);

private:

};
#endif // ACCOLADELANGUAGEINDENTER_H
