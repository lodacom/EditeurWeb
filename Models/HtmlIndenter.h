#ifndef HTMLINDENTER_H
#define HTMLINDENTER_H
#include <QString>
class HtmlIndenter{
public:
    HtmlIndenter();
    virtual ~HtmlIndenter();
    virtual int indentDetermin(QString line);

private:

};

#endif // HTMLINDENTER_H
