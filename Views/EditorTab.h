#ifndef EDITORTAB_H
#define EDITORTAB_H
#include <QTabWidget>
#include <string>
#include <iostream>
#include "CentralEditor.h"
using namespace std;
class EditorTab: public virtual QTabWidget{
public:
    EditorTab();
    //virtual bool alreadyOpened(string filePath);

private:

};

#endif // EDITORTAB_H
