#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/*#include <QStringListModel>

#include "../Controllers/JavaScriptHighlighter.h"
#include "../Controllers/HtmlHighlighter.h"
#include "../Controllers/CSSHighlighter.h"
#include "../Controllers/PhpHighlighter.h"
#include "Controllers/completion.h"*/
#include "CentralEditor.h"
#include "../Controllers/WorkSpaceTreeController.h"
//#include "htmltreewidget.h"
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
    void selectWorkSpace();
private:
    //void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();
    void setupColoration();
    void setupWorkSpaceDock();
    //void setupHtmlDock();
    CentralEditor *editor;
    /*QStringListModel* updateListVar();
    Completion *editor;
    Highlighter *highlighter;

    QCompleter *completer;
    QAbstractItemModel *modelFromFile(const QString& fileName);*/
    QMenu *menuColoration;
    WorkSpaceTree *treeView;
    //HtmlTreeWidget *htmlTreeWidget;
};

#endif
