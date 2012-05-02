#include "JavaScriptIndenter.h"
#include <iostream>
using namespace std;
JavaScriptIndenter::JavaScriptIndenter(){}
JavaScriptIndenter::~JavaScriptIndenter(){}
int JavaScriptIndenter::indentDetermin(QString line){
    int result;
    if((result = AccoladeLanguageIndenter::indentDetermin(line)) == 0){
        if(line.contains("<script") && line.contains("</script>")) return 0;
        else if(line.contains("<script")) return 1;
        else if(line.contains("</script>")) return -1;
    }
    return result;
}



