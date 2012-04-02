#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)//,completer(0)
{
    editor=new CentralEditor(parent);

    setupFileMenu();
    setupHelpMenu();
    //setupEditor();
    setupColoration();
    setupWorkSpaceDock();
    setCentralWidget(editor);
    QMainWindow::setWindowTitle(tr("WebShacke"));

    QDockWidget *dock = new QDockWidget("Html", this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    QWidget *dockContents = new QWidget;
    dock->setWidget(dockContents);
    this->htmlTreeWidget = new HtmlTreeWidget(this);
    QVBoxLayout *dockLayout = new QVBoxLayout;
    dockLayout->addWidget(htmlTreeWidget);
    dockContents->setLayout(dockLayout);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                tr("<p> Ok </p>"));
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

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

void MainWindow::selectWorkSpace()
{
    QString workSpacePath;
    workSpacePath = QFileDialog::getExistingDirectory(this, tr("Select workspace"), tr("/home"));
    treeView->selectWorkSpace(workSpacePath.toStdString());
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

    QAction *actionHTML = new QAction(tr("&HTML"),this);
    QAction *actionJavaScript = new QAction(tr("JavaScript"),this);
    QAction *actionPHP = new QAction(tr("PHP"),this);
    QAction *actionCSS = new QAction(tr("CSS"),this);

     menuColoration->addAction(actionCSS);
     menuColoration->addAction(actionHTML);
     menuColoration->addAction(actionJavaScript);
     menuColoration->addAction(actionPHP);

     QObject::connect(actionCSS, SIGNAL(triggered()),editor, SLOT(colorationCSS()));
     QObject::connect(actionPHP, SIGNAL(triggered()),editor, SLOT(colorationPHP()));
     QObject::connect(actionJavaScript, SIGNAL(triggered()),editor, SLOT(colorationJavaScript()));
     QObject::connect(actionHTML, SIGNAL(triggered()),editor, SLOT(colorationHTML()));
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
    QObject::connect(treeView, SIGNAL(fileOpened(QString)), this, SLOT(openFile(QString)));
}


/*QStringListModel* MainWindow::updateListVar()
{
    QStringList list_var;
    PhpDico *essai=new PhpDico(editor->document());
    list_var=essai->searchInFile();
    return new QStringListModel(list_var,completer);
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
}*/
