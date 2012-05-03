#include "PhpIndenter.h"
#include <iostream>
using namespace std;
PhpIndenter::PhpIndenter(){}
PhpIndenter::~PhpIndenter(){}
int PhpIndenter::indentDetermin(QString line){
    int result;
    if((result = AccoladeLanguageIndenter::indentDetermin(line)) == 0){
        if(line.contains("<?php") && line.contains("?>")) return 0;
        else if(line.contains("<?php")) return 1;
        else if(line.contains("?>")) return -1;
    }
    return result;
}


