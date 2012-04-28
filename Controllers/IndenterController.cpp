#include "IndenterController.h"

IndenterController::IndenterController(){
    currentLanguage = HTML_LANGUAGE;
    htmlIndenter = new HtmlIndenter();
}
IndenterController::~IndenterController(){}
int IndenterController::indentDetermin(QString previousLine){
    switch(currentLanguage){
        case HTML_LANGUAGE:
            return htmlIndenter->indentDetermin(previousLine);
            break;
    }
    return 0;
}

