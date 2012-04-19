#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QStringListModel>

#include "../Controllers/Highlighting/JavaScriptHighlighter.h"
#include "../Controllers/Highlighting/HtmlHighlighter.h"
#include "../Controllers/Highlighting/CSSHighlighter.h"
#include "../Controllers/Highlighting/PhpHighlighter.h"
#include "CentralEditor.h"
#include "../Controllers/WorkSpaceTreeController.h"
#include "HtmlTreeWidget.h"
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
    void selectWorkSpace();
private:
    void setupFileMenu();
    void setupHelpMenu();
    void setupColoration();
    void setupWorkSpaceDock();
    //void setupHtmlDock();


    CentralEditor *editor;

    QMenu *menuColoration;
    WorkSpaceTree *treeView;
    HtmlTreeWidget *htmlTreeWidget;
};

#endif
