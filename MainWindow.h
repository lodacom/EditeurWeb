#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Controllers/JavaScriptHighlighter.h"
#include "../Controllers/HtmlHighlighter.h"
#include "../Controllers/CSSHighlighter.h"
#include "../Controllers/PhpHighlighter.h"
#include "../Controllers/WorkSpaceTreeController.h"
#include "Controllers/completion.h"
//#include "WorkSpaceTree.h"
#include <QMainWindow>
#include<QApplication>
#include<QtGui>
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
   Q_OBJECT


public:

    MainWindow();
//! [class definition with macro]
    MainWindow(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void documentWasModified();
    void about();
    void openFile(const QString &path = QString());
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();

private:

    void setupHelpMenu();
    void setupColoration();
    void setupWorkSpaceDock();
    Highlighter *highlighter;

    QMenu *menuColoration;
    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionPHP;
    QAction *actionCSS;

    void init();
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void createVboxlayout();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    MainWindow *findMainWindow(const QString &fileName);
//QMdiArea *zoneCentrale;
   // QWidget *zoneCentrale;
    QTreeView *tree;
    //QTextBrowser *compilationtext;
    QTextEdit *textEdit;
    QString curFile;
    bool isUntitled;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *closeAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *selectallAct;





};

#endif


