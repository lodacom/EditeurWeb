#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Controllers/JavaScriptHighlighter.h"
#include "../Controllers/HtmlHighlighter.h"
#include "../Controllers/CSSHighlighter.h"
#include "../Controllers/PhpHighlighter.h"

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
    void newFile();
    void openFile(const QString &path = QString());
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();

private:
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();
    void setupColoration();

    QTextEdit *editor;
    Highlighter *highlighter;

    QMenu *menuColoration;
    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionPHP;
    QAction *actionCSS;
};

#endif
