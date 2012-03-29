#include <QtGui>

#include "MainWindow.h"
#include "../Models/LeftTree.h"

MainWindow::MainWindow()
{

init();
    setCurrentFile("hello");
setWindowTitle(tr("WebEditor"));
}

MainWindow::MainWindow(const QString &fileName)
{
    init();
    loadFile(fileName);

}


void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax WEBEDITOR"),
                tr("<p>The <b>Syntax Highlighter</b> example shows how " \
                   "to perform simple syntax highlighting by subclassing " \
                   "the QSyntaxHighlighter class and describing " \
                   "highlighting rules using regular expressions.</p>"));
}

void MainWindow::newFile()
{   if (maybeSave())
    textEdit->clear();
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
            textEdit->setPlainText(file.readAll());
    }
}

void MainWindow::colorationCSS()
{
        highlighter = new CSSHighlighter(textEdit->document());
}

void MainWindow::colorationHTML()
{
     highlighter = new HtmlHighlighter(textEdit->document());
}

void MainWindow::colorationJavaScript()
{
     highlighter = new JavaScriptHighlighter(textEdit->document());
}

void MainWindow::colorationPHP()
{
     highlighter = new PhpHighlighter(textEdit->document());
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
    LeftTree *treeView = new LeftTree();
    QVBoxLayout *dockLayout = new QVBoxLayout;
    dockLayout->addWidget(treeView);
    dockContents->setLayout(dockLayout);


}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}


void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),
                                                     QString(), tr("All types(*.*);;HTML-file (*.htm *.shtml *.shtm *.xhtm*.html);;CSS-file(*.css);;JavaScript file(*.js);;PHP-file(*.php *.php3 *.phtm);;C++ source file(*.h *.hpp *.hxx *.cpp *.cxx *.cc)"));
    if (!fileName.isEmpty()) {
        MainWindow *existing = findMainWindow(fileName);
        if (existing) {
            existing->show();
            existing->raise();
            existing->activateWindow();
            return;
        }

        if (isUntitled && textEdit->document()->isEmpty()
                && !isWindowModified()) {
            loadFile(fileName);
        } else {
            MainWindow *other = new MainWindow(fileName);
            if (other->isUntitled) {
                delete other;
                return;
            }
            other->move(x() + 40, y() + 40);
            other->show();
        }
    }
}

bool MainWindow::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), curFile, tr("All types(*.*);;HTML-file (*.htm *.shtml *.shtm *.xhtm*.html);;CSS-file(*.css);;JavaScript file(*.js);;PHP-file(*.php *.php3 *.phtm);;C++ source file(*.h *.hpp *.hxx *.cpp *.cxx *.cc)"));
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}


void MainWindow::documentWasModified()
{
    setWindowModified(true);
}

void MainWindow::init()
{
    setAttribute(Qt::WA_DeleteOnClose);

    isUntitled = true;

    QMdiArea *zoneCentrale = new QMdiArea;
textEdit = new QTextEdit;
        QTextEdit *zoneTexte1 = new QTextEdit;
       // QTextEdit *zoneTexte2 = new QTextEdit;

        QMdiSubWindow *sousFenetre0 = zoneCentrale->addSubWindow(textEdit);
       QMdiSubWindow *sousFenetre1 = zoneCentrale->addSubWindow(zoneTexte1);
       // QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);

        setCentralWidget(zoneCentrale);
        zoneCentrale->setViewMode(QMdiArea::TabbedView);

    //QWidget *zoneCentrale = new QWidget;

    /*   textEdit = new QTextEdit;
        textEdit->setGeometry(253,43,521,281);
        textEdit->setVisible(true);

        compilationtext= new QTextBrowser();
        compilationtext->setGeometry(50,320,931,84);
        compilationtext->setVisible(true);


       QFormLayout *layoute = new QFormLayout;

    //    layoute->addWidget();

        layoute->addWidget(textEdit);

        layoute->addWidget(compilationtext);

        //zoneCentrale->setLayout(layoute);

//        setCentralWidget(zoneCentrale);*/



    createActions();
    createMenus();
     createToolBars();
    setupHelpMenu();
    setupColoration();
    setupWorkSpaceDock();

    createStatusBar();

    readSettings();

    connect(textEdit->document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::createActions()
{
    newAct = new QAction(QIcon("images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon("images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon("images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    closeAct = new QAction(tr("&Close"), this);
    closeAct->setShortcut(tr("Ctrl+W"));
    closeAct->setStatusTip(tr("Close this window"));
    connect(closeAct, SIGNAL(triggered()), this, SLOT(close()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    cutAct = new QAction(QIcon("images/cut.png"), tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

    copyAct = new QAction(QIcon("images/copy.png"), tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

    pasteAct = new QAction(QIcon("images/paste.png"), tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

    undoAct= new QAction("undo",this);
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setStatusTip(tr("annuler l'operation"
                              "selection"));
    connect(undoAct, SIGNAL(triggered()), textEdit, SLOT(undo()));

    redoAct= new QAction("Redo",this);
    redoAct->setShortcut(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Retablir l'operation "
                              "selection"));
    connect(redoAct, SIGNAL(triggered()), textEdit, SLOT(redo()));

   /* aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));*/

    selectallAct= new QAction("Select All",this);
    selectallAct->setShortcut(QKeySequence::SelectAll);
    selectallAct->setStatusTip(tr("Selectionner tout"
                                  "selection"));
    connect(selectallAct,SIGNAL(triggered()),textEdit, SLOT(selectAll()));

    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));
}

//! [implicit tr context]
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
//! [implicit tr context]
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAct);
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(selectallAct);

    menuBar()->addSeparator();

}

void MainWindow::createToolBars()
{
//! [0]
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
//! [0]
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::readSettings()
{
    QSettings settings;
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settings;
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

bool MainWindow::maybeSave()
{
    if (textEdit->document()->isModified()) {
    QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Editeur"),
                     tr("Le texte a été modifié.\n"
                        "Voulez vous l'enregistrer?"),
                     QMessageBox::Save | QMessageBox::Discard
             | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Editeur"),
                             tr("Impossible de lire le fichier %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("Fichier téléchargé"), 2000);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Editeur"),
                             tr("Impossible d'enregistrer le fichier%1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("Fichier enregistré"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    static int sequenceNumber = 1;

    isUntitled = fileName.isEmpty();
    if (isUntitled) {
        curFile = tr("New%1").arg(sequenceNumber++);
    } else {
        curFile = QFileInfo(fileName).canonicalFilePath();
    }

    textEdit->document()->setModified(false);
    setWindowModified(false);
    setWindowFilePath(curFile);
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

MainWindow *MainWindow::findMainWindow(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QWidget *widget, qApp->topLevelWidgets()) {
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin && mainWin->curFile == canonicalFilePath)
            return mainWin;
    }
    return 0;
}

