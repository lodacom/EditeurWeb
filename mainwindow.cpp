#include <QtGui>
#include <QAction>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupFileMenu();
    setupHelpMenu();
    setupEditor();
    setupDisplay();

    setCentralWidget(editor);
    setWindowTitle(tr("Hightliter"));//titre de la fenêtre (inscrit dans la barre)
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
    tr("<p><b>Syntax Highlighter</b> help you " \
    "to shade keywords of Web langages like JavaScript, HTML</p>")
     );
}

void MainWindow::aboutJavaScript()
{
    /*renvoie sur la page d'aide du JavaScript*/
}

void MainWindow::shadeJavaScript()
{
    /*colorie le code en JavaScript après appui sur le boutton*/
}

void MainWindow::shadeHTML()
{
    /*colorie le code en HTML après appui sur le boutton*/
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
            tr("Ouvrir un fichier"), "", "JavaScript,HTML Files (*.js *.html *.htm)");

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QFile::ReadWrite | QFile::Text))
            editor->setPlainText(file.readAll());
    }
}

//! [1]
void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(12);

    editor = new QTextEdit;
    editor->setFont(font);

    js_shade = new jshighlighter(editor->document());
    //html_shade=new htmlhighlighter(editor->document());

    QFile file("mainwindow.h");
    if (file.open(QFile::ReadWrite | QFile::Text))
        editor->setPlainText(file.readAll());
}
//! [1]

void MainWindow::setupFileMenu()
{
    QMenu *fileMenu = new QMenu(tr("&Fichier"), this);
    menuBar()->addMenu(fileMenu);

    fileMenu->addAction(tr("&Nouveau fihier"), this, SLOT(newFile()),
                        QKeySequence::New);

    fileMenu->addAction(tr("&Ouvrir"), this, SLOT(openFile()),
                        QKeySequence::Open);

    fileMenu->addAction(tr("&Quitter"), qApp, SLOT(quit()),
                        QKeySequence::Quit);
}

void MainWindow::setupDisplay()
{
    QMenu *displayMenu = new QMenu(tr("&Affichage"), this);
    menuBar()->addMenu(displayMenu);

    QAction *survol=new QAction(tr("Mode de &coloration"),this);
    QMenu *shadeMenu= new QMenu(tr("Mode de &coloration"), this);
    displayMenu->insertMenu(survol,shadeMenu);

    shadeMenu->addAction(tr("&JavaScript"),this,SLOT(shadeJavaScript()));
    shadeMenu->addAction(tr("&HTML"),this,SLOT(shadeHTML()));
}

void MainWindow::setupHelpMenu()
{
    QMenu *helpMenu = new QMenu(tr("&Aide"), this);
    menuBar()->addMenu(helpMenu);

    helpMenu->addAction(tr("&à propos"), this, SLOT(about()));
    helpMenu->addAction(tr("à propos de &JavaScript"), qApp, SLOT(aboutJavaScript()));
}

