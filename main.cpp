#include <QApplication>

#include "Views/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.showMaximized();
    return app.exec();
}
