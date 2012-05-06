#include <QApplication>

#include "Views/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    QApplication::setWindowIcon(QIcon("Pics/App-icon.png"));
    window.showMaximized();
    Tools::init();
    return app.exec();
}
