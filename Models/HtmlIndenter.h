#ifndef HTMLINDENTER_H
#define HTMLINDENTER_H
#include <QString>
#include "Indenter.h"
class HtmlIndenter: public virtual Indenter{
public:
    HtmlIndenter();
    virtual ~HtmlIndenter();
    virtual int indentDetermin(QString line);

private:

};

#endif // HTMLINDENTER_H
