#include "CentralEditor.h"
#include "Models/PhpDico.h"

CentralEditor::CentralEditor(QWidget *parent):QTextEdit(parent),completer(0)
{
    editor = new Completion;
    completer = new QCompleter(this);

    setupEditor();
}

void CentralEditor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(14);

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
/*...............................................................................................................*/
