#include "CentralEditor.h"
#include "Models/PhpDico.h"

CentralEditor::CentralEditor(QWidget *parent):QTextEdit(parent),completer(0)
{
    editor = new Completion;
    completer = new QCompleter(this);

    setupEditor();
    //setupColoration();
}

void CentralEditor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(12);

    editor->setFont(font);
    editor->setCompleter(completer);
}

/*Partie coloration et complétion*/
/*...............................................................................................................*/
QStringListModel* CentralEditor::updateListVar()
{
    QStringList list_var;
    PhpDico *essai=new PhpDico(editor->document());
    list_var=essai->searchInFile();
    return new QStringListModel(list_var,completer);
}

QAbstractItemModel *CentralEditor::modelFromFile(const QString& fileName)
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

void CentralEditor::colorationCSS()
{
    highlighter = new CSSHighlighter(editor->document());
    completer->setModelSorting(QCompleter::UnsortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);
    completer->setModel(modelFromFile(":/Resources/CSS.txt"));
}

void CentralEditor::colorationHTML()
{
     highlighter = new HtmlHighlighter(editor->document());
     completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/HTML.txt"));
}

void CentralEditor::colorationJavaScript()
{
     highlighter = new JavaScriptHighlighter(editor->document());
     completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/JavaScript.txt"));
}

void CentralEditor::colorationPHP()
{
     highlighter = new PhpHighlighter(editor->document());

     completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/PHP.txt"));
}

void CentralEditor::setupColoration(QMenu* menuColoration)
{
   /* menuColoration = new QMenu(tr("&Coloration"),this);
    menuBar()->addMenu(menuColoration);*/

    actionHTML = new QAction(tr("&HTML"),this);
    actionJavaScript = new QAction(tr("JavaScript"),this);
    actionPHP = new QAction(tr("PHP"),this);
    actionCSS = new QAction(tr("CSS"),this);

     menuColoration->addAction(actionCSS);
     menuColoration->addAction(actionHTML);
     menuColoration->addAction(actionJavaScript);
     menuColoration->addAction(actionPHP);

     /*QObject::connect(actionCSS, SIGNAL(triggered()), this, SLOT(colorationCSS()));
     QObject::connect(actionPHP, SIGNAL(triggered()), this, SLOT(colorationPHP()));
     QObject::connect(actionJavaScript, SIGNAL(triggered()), this, SLOT(colorationJavaScript()));
     QObject::connect(actionHTML, SIGNAL(triggered()), this, SLOT(colorationHTML()));*/
}
/*...............................................................................................................*/
