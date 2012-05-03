
#include "CssIndenter.h"
#include <iostream>
using namespace std;
CssIndenter::CssIndenter(){}
CssIndenter::~CssIndenter(){}
int CssIndenter::indentDetermin(QString line){
    int result;
    if((result = AccoladeLanguageIndenter::indentDetermin(line)) == 0){
        if(line.contains("<style") && line.contains("</style>")) return 0;
        else if(line.contains("<style")) return 1;
        else if(line.contains("</style>")) return -1;
    }
    return result;
}


