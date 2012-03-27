#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Controllers/Highlighting/JavaScriptHighlighter.h"
#include "../Controllers/Highlighting/HtmlHighlighter.h"
#include "../Controllers/Highlighting/CSSHighlighter.h"
#include "../Controllers/Highlighting/PhpHighlighter.h"
#include "../Controllers/WorkSpaceTreeController.h"
#include "Controllers/completion.h"

#include "htmltreewidget.h"
#include "WorkSpaceTree.h"


QT_BEGIN_NAMESPACE
class QTextEdit;
class QTreeWidgetItem;
class QWebView;
class QTreeWidget;
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
    void openFile(const QModelIndex& index);
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();
    void selectWorkSpace();
private:
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();
    void setupColoration();
    void setupWorkSpaceDock();
    void setupHtmlDock();
    Completion *editor;
    Highlighter *highlighter;

    QMenu *menuColoration;
    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionPHP;
    QAction *actionCSS;

    QAbstractItemModel *modelFromFile(const QString& fileName);
    WorkSpaceTree *treeView;

    QCompleter *completer;
    HtmlTreeWidget *htmlTreeWidget;
};

#endif
