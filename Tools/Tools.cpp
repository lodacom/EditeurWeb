#include"Tools.h"

void Tools::init(){
    htmlIcon = new QIcon("Pics/File-HTML-icon.png");
    jsIcon = new QIcon("Pics/File-JS-icon.png");
    phpIcon = new QIcon("Pics/File-PHP-icon.png");
    cssIcon = new QIcon("Pics/File-CSS-icon.png");
    fileIcon = new QIcon("Pics/File-icon.png");
    projectIcon = new QIcon("Pics/Project-icon.png");
}

string Tools::getExtension(const string filePath){
    size_t position = filePath.find_last_of('.');
    if (position == (size_t)-1){
        return "";
    }
    else{
        return filePath.substr(position + 1, filePath.size());
    }
    return "";
}

string Tools::getName(const string filePath){
    size_t position = filePath.find_last_of('/');
    if (position == (size_t)-1){
        return "";
    }
    else{
        return filePath.substr(position + 1, filePath.size());
    }
    return "";
}

QString Tools::getQExtension(const QString filePath){
    return QString(getExtension(filePath.toStdString()).c_str());
}

QString Tools::getQName(const QString filePath){
    return QString(getName(filePath.toStdString()).c_str());
}


QIcon* Tools::phpIcon;
QIcon* Tools::htmlIcon;
QIcon* Tools::cssIcon;
QIcon* Tools::jsIcon;
QIcon* Tools::fileIcon;
QIcon* Tools::projectIcon;
