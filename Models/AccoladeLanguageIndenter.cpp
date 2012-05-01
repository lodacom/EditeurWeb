#include "AccoladeLanguageIndenter.h"

AccoladeLanguageIndenter::AccoladeLanguageIndenter(){}
AccoladeLanguageIndenter::~AccoladeLanguageIndenter(){}
int AccoladeLanguageIndenter::indentDetermin(QString line){
    if(line.size() > 0 && line.contains("{") && !line.contains("}") ){
        return 1;
    }
    else if(line.contains("}")){
        return -1;
    }
    else{
    }
        return 0;
}

