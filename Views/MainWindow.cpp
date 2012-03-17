#include <QtGui>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupFileMenu();
    setupHelpMenu();
    setupEditor();
    setupColoration();
    setupWorkSpaceDock();
    setCentralWidget(editor);
    setWindowTitle(tr("Syntax Highlighter"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                tr("<p>The <b>Syntax Highlighter</b> example shows how " \
                   "to perform simple syntax highlighting by subclassing " \
                   "the QSyntaxHighlighter class and describing " \
                   "highlighting rules using regular expressions.</p>"));
}

void MainWindow::newFile()
{
    editor->clear();
}

void MainWindow::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "", "C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

void MainWindow::colorationCSS()
{
        highlighter = new CSSHighlighter(editor->document());
}

void MainWindow::colorationHTML()
{
     highlighter = new HtmlHighlighter(editor->document());
}

void MainWindow::colorationJavaScript()
{
     highlighter = new JavaScriptHighlighter(editor->document());
}

void MainWindow::colorationPHP()
{
     highlighter = new PhpHighlighter(editor->document());
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    editor = new QTextEdit;
    editor->setFont(font);

    highlighter = new HtmlHighlighter(editor->document());
}

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()),
                        QKeySequence::New);

    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()),
                        QKeySequence::Open);

    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()),
                        QKeySequence::Quit);
}

void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction(tr("&About"), this, SLOT(about()));
    helpMenu->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));
}

void MainWindow::setupColoration()
{
    menuColoration = new QMenu(tr("&Coloration"),this);
    menuBar()->addMenu(menuColoration);

    actionHTML = new QAction(tr("&HTML"),this);
    actionJavaScript = new QAction(tr("JavaScript"),this);
    actionPHP = new QAction(tr("PHP"),this);
    actionCSS = new QAction(tr("CSS"),this);

     menuColoration->addAction(actionCSS);
     menuColoration->addAction(actionHTML);
     menuColoration->addAction(actionJavaScript);
     menuColoration->addAction(actionPHP);

     QObject::connect(actionCSS, SIGNAL(triggered()), this, SLOT(colorationCSS()));
     QObject::connect(actionPHP, SIGNAL(triggered()), this, SLOT(colorationPHP()));
     QObject::connect(actionJavaScript, SIGNAL(triggered()), this, SLOT(colorationJavaScript()));
     QObject::connect(actionHTML, SIGNAL(triggered()), this, SLOT(colorationHTML()));
}

void MainWindow::setupWorkSpaceDock(){
    QDockWidget *dock = new QDockWidget("WorkSpace", this);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    QWidget *dockContents = new QWidget;
    dock->setWidget(dockContents);

    QTreeView *treeView = new QTreeView;
    WorkSpaceTreeController *wsController = new WorkSpaceTreeController();
    treeView->setModel(wsController->getQItemModel());
    QVBoxLayout *dockLayout = new QVBoxLayout;
    dockLayout->addWidget(treeView);
    dockContents->setLayout(dockLayout);
}
