#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)//,completer(0)
{
   // editor=new CentralEditor(parent);
    init();
    //setCurrentFile("hello");
}

/*MainWindow::MainWindow(const QString &fileName)
{
    init();
    //loadFile(fileName);
}*/

void MainWindow::init()
{
    setAttribute(Qt::WA_DeleteOnClose);

    //isUntitled = true;

    zoneCentrale = new QMdiArea;
    zoneCentrale->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    zoneCentrale->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setCentralWidget(zoneCentrale);
    connect(zoneCentrale, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(updateMenus()));
    windowMapper = new QSignalMapper(this);
    connect(windowMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(setActiveSubWindow(QWidget*)));

    setupWorkSpaceDock();
    //setupColoration();
    createActions();
    createMenus();
    updateMenus();
    createToolBars();
    createStatusBar();

    readSettings();

    QMainWindow::setWindowTitle(tr("WebShake"));
    setUnifiedTitleAndToolBarOnMac(true);


    QDockWidget *dock = new QDockWidget("Html", this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    QWidget *dockContents = new QWidget;
    dock->setWidget(dockContents);
    this->htmlTreeWidget = new HtmlTreeWidget(this);
    QVBoxLayout *dockLayout = new QVBoxLayout;
    dockLayout->addWidget(htmlTreeWidget);
    dockContents->setLayout(dockLayout);
}

void MainWindow::createActions()
{
    newAct = new QAction(QIcon(":/Pics/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon(":/Pics/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/Pics/save.png"), tr("&Save"), this);
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

    separatorAct = new QAction(this);
    separatorAct->setSeparator(true);

    closeAllAct = new QAction(tr("Close &All"), this);
    closeAllAct->setStatusTip(tr("Close all the windows"));
    connect(closeAllAct, SIGNAL(triggered()),
            zoneCentrale, SLOT(closeAllSubWindows()));

    tileAct = new QAction(tr("&Tile"), this);
    tileAct->setStatusTip(tr("Tile the windows"));
    connect(tileAct, SIGNAL(triggered()), zoneCentrale, SLOT(tileSubWindows()));

    cascadeAct = new QAction(tr("&Cascade"), this);
    cascadeAct->setStatusTip(tr("Cascade the windows"));
    connect(cascadeAct, SIGNAL(triggered()), zoneCentrale, SLOT(cascadeSubWindows()));

    nextAct = new QAction(tr("Ne&xt"), this);
    nextAct->setShortcuts(QKeySequence::NextChild);
    nextAct->setStatusTip(tr("Move the focus to the next window"));
    connect(nextAct, SIGNAL(triggered()),
            zoneCentrale, SLOT(activateNextSubWindow()));

    previousAct = new QAction(tr("Pre&vious"), this);
    previousAct->setShortcuts(QKeySequence::PreviousChild);
    previousAct->setStatusTip(tr("Move the focus to the previous "
                                 "window"));
    connect(previousAct, SIGNAL(triggered()),
            zoneCentrale, SLOT(activatePreviousSubWindow()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    cutAct = new QAction(QIcon(":/Pics/cut.png"), tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, SIGNAL(triggered()),this, SLOT(cut()));

    copyAct = new QAction(QIcon(":/Pics/copy.png"), tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, SIGNAL(triggered()),this, SLOT(copy()));

    pasteAct = new QAction(QIcon(":/Pics/paste.png"), tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, SIGNAL(triggered()),this, SLOT(paste()));

    undoAct= new QAction("undo",this);
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Cancel this operation"
                              "Select"));
    connect(undoAct, SIGNAL(triggered()),this, SLOT(undo()));

    redoAct= new QAction("Redo",this);
    redoAct->setShortcut(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Restore this operation "
                              "Select"));
    connect(redoAct, SIGNAL(triggered()),this, SLOT(redo()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &WebShake"), this);
    aboutQtAct->setStatusTip(tr("Show the WebShake About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    selectallAct= new QAction("Select All",this);
    selectallAct->setShortcut(QKeySequence::SelectAll);
    selectallAct->setStatusTip(tr("Select all"
                                  "Select"));
    connect(selectallAct,SIGNAL(triggered()),this, SLOT(selectAll()));

    actionHTML = new QAction(tr("&HTML"),this);
    actionJavaScript = new QAction(tr("JavaScript"),this);
    actionPHP = new QAction(tr("PHP"),this);
    actionCSS = new QAction(tr("CSS"),this);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
//! [implicit tr context]
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    QAction *action = fileMenu->addAction(tr("Switch layout direction"));
    connect(action, SIGNAL(triggered()), this, SLOT(switchLayoutDirection()));

    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(selectallAct);

    windowMenu = menuBar()->addMenu(tr("&Window"));
    updateWindowMenu();
    connect(windowMenu, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));

    menuColoration = menuBar()->addMenu(tr("&Coloration"));
    menuColoration->addAction(actionCSS);
    menuColoration->addAction(actionHTML);
    menuColoration->addAction(actionJavaScript);
    menuColoration->addAction(actionPHP);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    zoneCentrale->closeAllSubWindows();
    if (zoneCentrale->currentSubWindow())
    {
        event->ignore();
    }
    else
    {
        writeSettings();
        event->accept();
    }
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

void MainWindow::about()
{
    QMessageBox::about(this, tr("About WebShake"),
                tr("<p> Ok </p>"));
}

void MainWindow::newFile()
{
    CentralEditor *child = createMdiChild();
    child->newFile();
    child->show();
}

/*void MainWindow::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open File"), "", "Web Files (*.html *.xhtml *.htm *.php *.css *.js)");

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}*/

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open File"), "", "Web Files (*.html *.xhtml *.htm *.php *.css *.js)");
    if (!fileName.isEmpty())
    {
        QMdiSubWindow *existing = findMdiChild(fileName);
        if (existing)
        {
            zoneCentrale->setActiveSubWindow(existing);
            return;
        }

        CentralEditor *child = createMdiChild();
        if (child->loadFile(fileName))
        {
            statusBar()->showMessage(tr("File loaded"), 2000);
            child->show();
        }
        else
        {
            child->close();
        }
    }
}

void MainWindow::save()
{
    if (activeMdiChild() && activeMdiChild()->save())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::saveAs()
{
    if (activeMdiChild() && activeMdiChild()->saveAs())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::cut()
{
    if (activeMdiChild())
        activeMdiChild()->cut();
}

void MainWindow::copy()
{
    if (activeMdiChild())
        activeMdiChild()->copy();
}

void MainWindow::paste()
{
    if (activeMdiChild())
        activeMdiChild()->paste();
}

void MainWindow::undo()
{
    if (activeMdiChild())
        activeMdiChild()->undo();
}

void MainWindow::redo()
{
    if (activeMdiChild())
        activeMdiChild()->redo();
}

void MainWindow::selectAll()
{
    if (activeMdiChild())
        activeMdiChild()->selectAll();
}

void MainWindow::documentWasModified()
{
    setWindowModified(true);
}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild() != 0);
    saveAct->setEnabled(hasMdiChild);
    saveAsAct->setEnabled(hasMdiChild);
    pasteAct->setEnabled(hasMdiChild);
    closeAct->setEnabled(hasMdiChild);
    closeAllAct->setEnabled(hasMdiChild);
    tileAct->setEnabled(hasMdiChild);
    cascadeAct->setEnabled(hasMdiChild);
    nextAct->setEnabled(hasMdiChild);
    previousAct->setEnabled(hasMdiChild);
    separatorAct->setVisible(hasMdiChild);

    bool hasSelection = (activeMdiChild() &&
                         activeMdiChild()->textCursor().hasSelection());
    cutAct->setEnabled(hasSelection);
    copyAct->setEnabled(hasSelection);
}

void MainWindow::updateWindowMenu()
{
    windowMenu->clear();
    windowMenu->addAction(closeAct);
    windowMenu->addAction(closeAllAct);
    windowMenu->addSeparator();
    windowMenu->addAction(tileAct);
    windowMenu->addAction(cascadeAct);
    windowMenu->addSeparator();
    windowMenu->addAction(nextAct);
    windowMenu->addAction(previousAct);
    windowMenu->addAction(separatorAct);


    QList<QMdiSubWindow *> windows = zoneCentrale->subWindowList();
    separatorAct->setVisible(!windows.isEmpty());

    for (int i = 0; i < windows.size(); ++i)
    {
        CentralEditor *child = qobject_cast<CentralEditor *>(windows.at(i)->widget());

        QString text;
        if (i < 9)
        {
            text = tr("&%1 %2").arg(i + 1)
                               .arg(child->userFriendlyCurrentFile());
        }
        else
        {
            text = tr("%1 %2").arg(i + 1)
                              .arg(child->userFriendlyCurrentFile());
        }
        QAction *action  = windowMenu->addAction(text);
        action->setCheckable(true);
        action ->setChecked(child == activeMdiChild());
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
        windowMapper->setMapping(action, windows.at(i));
    }
}

CentralEditor *MainWindow::createMdiChild()
{
    CentralEditor *child = new CentralEditor;
    zoneCentrale->addSubWindow(child);

    connect(child, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));
    connect(actionHTML, SIGNAL(triggered()),
            child, SLOT(colorationHTML()));
    connect(actionJavaScript, SIGNAL(triggered()),
            child, SLOT(colorationJavaScript()));
    connect(actionPHP, SIGNAL(triggered()),
            child, SLOT(colorationPHP()));
    connect(actionCSS, SIGNAL(triggered()),
            child, SLOT(colorationCSS()));

    return child;
}

CentralEditor *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = zoneCentrale->activeSubWindow())
        return qobject_cast<CentralEditor *>(activeSubWindow->widget());
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

    foreach (QMdiSubWindow *window, zoneCentrale->subWindowList())
    {
        CentralEditor *mdiChild = qobject_cast<CentralEditor *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::switchLayoutDirection()
{
    if (layoutDirection() == Qt::LeftToRight)
        qApp->setLayoutDirection(Qt::RightToLeft);
    else
        qApp->setLayoutDirection(Qt::LeftToRight);
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;
    zoneCentrale->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}


void MainWindow::selectWorkSpace()
{
    QString workSpacePath;
    workSpacePath = QFileDialog::getExistingDirectory(this, tr("Select workspace"), tr("/home"));
    treeView->selectWorkSpace(workSpacePath.toStdString());
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
