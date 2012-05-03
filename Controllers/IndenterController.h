#ifndef INDENTERCONTROLLER_H
#define INDENTERCONTROLLER_H
#include <QObject>
#include <QLine>
#include "Models/HtmlIndenter.h"
#include "Models/PhpIndenter.h"
#include "Models/JavaScriptIndenter.h"
#include "Models/CssIndenter.h"
#define UNKNOWN_LANGUAGE -1
#define HTML_LANGUAGE 0
#define CSS_LANGUAGE 1
#define JS_LANGUAGE 2
#define PHP_LANGUAGE 3
class IndenterController:public QObject{
Q_OBJECT

public:
    IndenterController();
    virtual ~IndenterController();
    virtual int indentDetermin(QString line);
    virtual void setLanguage(int language);
private:
    HtmlIndenter *htmlIndenter;
    PhpIndenter *phpIndenter;
    JavaScriptIndenter *javascriptIndenter;
    CssIndenter *cssIndenter;
    int currentLanguage;


};

#endif // INDENTERCONTROLLER_H
