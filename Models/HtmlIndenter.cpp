#include "HtmlIndenter.h"


HtmlIndenter::HtmlIndenter(){}
HtmlIndenter::~HtmlIndenter(){}
int HtmlIndenter::indentDetermin(QString line){
    if(line.size() > 0 && line[0] == '<' && !line.contains("</") && !line.contains("/>")){
        return 1;
    }
    else if(line.size() > 1 && line[0] == '<' && line[1] == '/'){
        return -1;
    }
    else{
    }
        return 0;
}
