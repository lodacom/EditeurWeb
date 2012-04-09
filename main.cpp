#include <QApplication>

#include "Views/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    QApplication::setWindowIcon(QIcon("Pics/App-icon.png"));
    window.showMaximized();

    /* Provisoire, test de l'arborescence. Signé : Abdel */
    Q_INIT_RESOURCE(examples);
    QFile file(":/Examples/jocrisse.html");
    file.open(QIODevice::ReadOnly);
    SyntaxTree model(file.readAll());
    file.close();

    QTreeView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Simple Tree Model"));
    view.show();

    return app.exec();
}
