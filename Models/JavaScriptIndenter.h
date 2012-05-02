#ifndef JAVASCRIPTINDENTER_H
#define JAVASCRIPTINDENTER_H
#include "AccoladeLanguageIndenter.h"
class JavaScriptIndenter:public virtual AccoladeLanguageIndenter{
public:
    JavaScriptIndenter();
    virtual ~JavaScriptIndenter();
    virtual int indentDetermin(QString line);
};
#endif // JAVASCRIPTINDENTER_H
