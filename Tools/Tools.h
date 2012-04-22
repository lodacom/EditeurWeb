#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include <QString>
#include <QIcon>
using namespace std;
class Tools{
public:
    static void init();
    static QIcon *phpIcon, *htmlIcon, *jsIcon, *cssIcon, *fileIcon, *projectIcon;
    static string getExtension(const string filePath);
    static string getName(const string filePath);
    static QString getQExtension(const QString filePath);
    static QString getQName(const QString filePath);
};

#endif // TOOLS_H

