#include "CentralEditor.h"
//#include "Models/PhpDico.h"

CentralEditor::CentralEditor(QWidget *parent):QTextEdit(parent)
{
    completerController = new CompleterController();

    setupEditor();
}

void CentralEditor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    this->setFont(font);

}

/*Partie coloration et complétion*/
/*...............................................................................................................*/
/*QStringListModel* CentralEditor::updateListVar()
{
    QStringList list_var;
    PhpDico *essai=new PhpDico(editor->document());
    list_var=essai->searchInFile();
    return new QStringListModel(list_var,completer);
}
*/
/*QAbstractItemModel *CentralEditor::modelFromFile(const QString& fileName)
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
*/
void CentralEditor::colorationCSS()
{
    highlighter = new CSSHighlighter(this->document());
    /*completer->setModelSorting(QCompleter::UnsortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);
    completer->setModel(modelFromFile(":/Resources/CSS.txt"));*/
}

void CentralEditor::colorationHTML()
{
     highlighter = new HtmlHighlighter(this->document());
     /*completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/HTML.txt"));*/
}

void CentralEditor::colorationJavaScript()
{
     highlighter = new JavaScriptHighlighter(this->document());
     /*completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/JavaScript.txt"));*/
}

void CentralEditor::colorationPHP()
{
     highlighter = new PhpHighlighter(this->document());

     /*completer->setModelSorting(QCompleter::UnsortedModel);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     completer->setWrapAround(false);
     completer->setModel(modelFromFile(":/Resources/PHP.txt"));*/
}
/*...............................................................................................................*/
