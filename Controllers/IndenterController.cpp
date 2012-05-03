#include "IndenterController.h"
#include <iostream>
using namespace std;
IndenterController::IndenterController(){
    currentLanguage = UNKNOWN_LANGUAGE;
    htmlIndenter = new HtmlIndenter();
    phpIndenter = new PhpIndenter();
    javascriptIndenter = new JavaScriptIndenter();
    cssIndenter = new CssIndenter();
}
IndenterController::~IndenterController(){}
int IndenterController::indentDetermin(QString line){
    switch(currentLanguage){
        case UNKNOWN_LANGUAGE:
            return 0;
            break;
        case HTML_LANGUAGE:
            return htmlIndenter->indentDetermin(line);
            break;
        case PHP_LANGUAGE:
            return phpIndenter->indentDetermin(line);
            break;
        case JS_LANGUAGE:
            return javascriptIndenter->indentDetermin(line);
            break;
        case CSS_LANGUAGE:
            return cssIndenter->indentDetermin(line);
            break;
    }
    return 0;
}

void IndenterController::setLanguage(int language){
    currentLanguage = language;
}
