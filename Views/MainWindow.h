#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QApplication>

#include "../Controllers/Highlighting/JavaScriptHighlighter.h"
#include "../Controllers/Highlighting/HtmlHighlighter.h"
#include "../Controllers/Highlighting/CSSHighlighter.h"
#include "../Controllers/Highlighting/PhpHighlighter.h"
#include "CentralEditor.h"
#include "../Controllers/WorkSpaceTreeController.h"
#include "HtmlTreeWidget.h"
#include "WorkSpaceTree.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
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
    MainWindow(const QString &fileName);

public slots:
    void open();
    void save();
    void saveAs();
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();
    void selectAll();
    void updateWindowMenu();
    void updateMenus();
    CentralEditor *createMdiChild();
    void documentWasModified();
    void switchLayoutDirection();
    void setActiveSubWindow(QWidget *window);
    void about();
    void newFile();
    //void openFile(const QString &path = QString());
    void selectWorkSpace();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void init();
    //void setupColoration();
    void setupWorkSpaceDock();
    //void setupHtmlDock();

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void createVboxlayout();
    void writeSettings();

    CentralEditor *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);

    QString strippedName(const QString &fullFileName);
    WorkSpaceTree *treeView;
    HtmlTreeWidget *htmlTreeWidget;

    QMdiArea *zoneCentrale;
    QSignalMapper *windowMapper;

    QMenu *menuColoration;
    QMenu *windowMenu;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionPHP;
    QAction *actionCSS;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *closeAct;
    QAction *closeAllAct;
    QAction *tileAct;
    QAction *cascadeAct;
    QAction *nextAct;
    QAction *previousAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *selectallAct;
    QAction *separatorAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
