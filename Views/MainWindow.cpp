#include <QtGui>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),completer(0)
{
    editor = new Completion;
    completer = new QCompleter(this);

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
void MainWindow::openFile(const QModelIndex& index){
    list<int> *elementWay = new list<int>();
    QModelIndex indexCopie = QModelIndex(index);
    while (indexCopie != QModelIndex()){
        elementWay->push_front(indexCopie.row());
        indexCopie = indexCopie.parent();
    }
    string elementPath = treeView->getFilePath(elementWay);
    if (elementPath != ""){
        QFile file(QString(elementPath.c_str()));
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}
void MainWindow::selectWorkSpace(){
    QString workSpacePath;
    workSpacePath = QFileDialog::getExistingDirectory(this, tr("Select workspace"), tr("/home"));
    treeView->selectWorkSpace(workSpacePath.toStdString());
}

void MainWindow::colorationCSS()
{
    highlighter = new CSSHighlighter(editor->document());
    completer->setModelSorting(QCompleter::UnsortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);
    completer->setModel(modelFromFile(":/Resources/CSS.txt"));
}

void MainWindow::colorationHTML()
{
     highlighter = new HtmlHighlighter(editor->document());
     completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/HTML.txt"));
}

void MainWindow::colorationJavaScript()
{
     highlighter = new JavaScriptHighlighter(editor->document());
     completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/JavaScript.txt"));
}

void MainWindow::colorationPHP()
{
     highlighter = new PhpHighlighter(editor->document());
     completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/PHP.txt"));
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(12);

    editor->setFont(font);
    editor->setCompleter(completer);

    //highlighter = new HtmlHighlighter(editor->document());
}

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&New"), this, SLOT(newFile()),
                        QKeySequence::New);

    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()),
                        QKeySequence::Open);
    fileMenu->addAction(tr("&Select WorkSpace"), this, SLOT(selectWorkSpace()));

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

void MainWindow::setupWorkSpaceDock()
{
    QDockWidget *dock = new QDockWidget("WorkSpace", this);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    QWidget *dockContents = new QWidget;
    dock->setWidget(dockContents);
        treeView = new WorkSpaceTree();
    QVBoxLayout *dockLayout = new QVBoxLayout;
    dockLayout->addWidget(treeView);
    dockContents->setLayout(dockLayout);
    QObject::connect(treeView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(openFile(const QModelIndex &)));
}


QAbstractItemModel *MainWindow::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);

#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd())
    {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << line.trimmed();
    }

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, completer);
}
