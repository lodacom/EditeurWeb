#ifndef PHPINDENTER_H
#define PHPINDENTER_H
#include "AccoladeLanguageIndenter.h"
class PhpIndenter: public virtual AccoladeLanguageIndenter{
public:
    PhpIndenter();
    virtual ~PhpIndenter();
    virtual int indentDetermin(QString line);

private:

};

#endif // PHPINDENTER_H
