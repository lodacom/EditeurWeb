#ifndef INDENTERCONTROLLER_H
#define INDENTERCONTROLLER_H
#include <QObject>
#include <QLine>
#include "Models/HtmlIndenter.h"
#define HTML_LANGUAGE 0
#define CSS_LANGUAGE 1
#define JS_LANGUAGE 2
#define PHP_LANGUAGE 3
class IndenterController:public QObject{
Q_OBJECT

public:
    IndenterController();
    virtual ~IndenterController();
    virtual int indentDetermin(QString previousLine);
    //virtual int languageCheck();
private:
    HtmlIndenter *htmlIndenter;
    int currentLanguage;


};

#endif // INDENTERCONTROLLER_H
