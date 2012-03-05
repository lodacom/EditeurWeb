#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "jshighlighter.h"
#include "htmlhighlighter.h"

QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void about();
    void aboutJavaScript();
    void shadeJavaScript();
    void shadeHTML();
    void newFile();
    void openFile(const QString &path = QString());

private:
    void setupEditor();
    void setupDisplay();
    void setupFileMenu();
    void setupHelpMenu();

    QTextEdit *editor;
    jshighlighter *js_shade;
    htmlhighlighter *html_shade;
};

#endif
