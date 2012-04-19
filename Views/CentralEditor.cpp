#include "CentralEditor.h"
#include <QCompleter>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QtDebug>
#include <QApplication>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>
#include <QStringListModel>

CentralEditor::CentralEditor(QWidget *parent):QTextEdit(parent),completion_text(0)
{
    completion_text = new QCompleter(this);

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

/*Partie complétion*/
/*...............................................................................................................*/
QAbstractItemModel *CentralEditor::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completion_text);

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
    return new QStringListModel(words, completion_text);
}

QCompleter *CentralEditor::completer() const
{
    return completion_text;//on retourne tous les mots affiliés à ceux qu'on a trouvé
}

void CentralEditor::insertCompletion(const QString& completion)
{

   if (completion_text->widget() != this)
        return;
    QTextCursor tc= textCursor();
    int extra = completion.length() - completion_text->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);//on met le curseur à la fin du mot complété
    tc.insertText(completion.right(extra));//complétion (rajout du reste du mot choisi)à droite
    setTextCursor(tc);//mise en place de la suivie du curseur
}

QString CentralEditor::textUnderCursor() const
{
    QTextCursor tc= textCursor();
    tc.select(QTextCursor::WordUnderCursor);//on sélectionne le mot que l'utilisateur a choisi
    return tc.selectedText();//on renvoie le mot choisi par l'utilisateur
}

void CentralEditor::setCompleter(QCompleter *p_completer)
{
    if (completion_text)
        QObject::disconnect(completion_text, 0,this, 0);//on déconnecte l'auto-compléteur de la fenêtre

    completion_text = p_completer;

    if (!completion_text)
        return;

    completion_text->setWidget(this);//on met en place la completion
    completion_text->setCompletionMode(QCompleter::PopupCompletion);//mode de complétion
    completion_text->setCaseSensitivity(Qt::CaseInsensitive);//non prise en compte de la casse (majuscule, minuscule)
    QObject::connect(completion_text, SIGNAL(activated(QString)),this, SLOT(insertCompletion(QString)));
   /* on connecte le compléteur à la fenêtre principale
      la complétion s'active sur lactivation du clavier
      et on fait l'action insertCompletion*/

}

void CentralEditor::focusInEvent(QFocusEvent *e)
{
    if (completion_text)//on regarde si la complétion est lancée
        completion_text->setWidget(this);
    QTextEdit::focusInEvent(e);
}

void CentralEditor::keyPressEvent(QKeyEvent *e)
{
    if (completion_text && completion_text->popup()->isVisible())
    {
        //Les clés suivantes sont suivies par le compléteur
       switch (e->key())
       {
       case Qt::Key_Enter:
       case Qt::Key_Return:
       case Qt::Key_Escape:
       case Qt::Key_Tab:
       case Qt::Key_Backtab:
            e->ignore();
            return; // on laisse le compléteur avec son comportement par défaut
       default:
           break;
       }
    }

    bool isShortcut = ((e->modifiers() & Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!completion_text || !isShortcut) // do not process the shortcut when we have a completer
        QTextEdit::keyPressEvent(e);

    const bool ctrlOrShift = e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier);
    if (!completion_text || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word ??
    bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 1
                      || eow.contains(e->text().right(1))))
    {
        completion_text->popup()->hide();
        return;
    }

    if (completionPrefix != completion_text->completionPrefix())
    {
        completion_text->setCompletionPrefix(completionPrefix);
        completion_text->popup()->setCurrentIndex(completion_text->completionModel()->index(0, 0));
    }

    /*Ci-dessous on met en place le rectangle avec srcoll bar qui apparaitra
      *lors de la complétion. On calcule sa lageur avec le plus long mot trouvé
      * et sa hauteur avec le nombre de mots trouvés*/
    QRect cr = cursorRect();
    cr.setWidth(completion_text->popup()->sizeHintForColumn(0)
                + completion_text->popup()->verticalScrollBar()->sizeHint().width());
    completion_text->complete(cr); // popup it up!
}

/*Partie coloration et utilisation du compléteur*/
/*...............................................................................................................*/
void CentralEditor::colorationCSS()
{
    highlighter = new CSSHighlighter(this->document());

    completion_text->setModelSorting(QCompleter::UnsortedModel);
    completion_text->setCaseSensitivity(Qt::CaseInsensitive);
    completion_text->setWrapAround(false);
    completion_text->setModel(modelFromFile(":/Resources/CSS.txt"));

    this->setCompleter(completion_text);
}

void CentralEditor::colorationHTML()
{
     highlighter = new HtmlHighlighter(this->document());

     completion_text->setModelSorting(QCompleter::UnsortedModel);
     completion_text->setCaseSensitivity(Qt::CaseInsensitive);
     completion_text->setWrapAround(false);
     completion_text->setModel(modelFromFile(":/Resources/HTML.txt"));

     this->setCompleter(completion_text);
}

void CentralEditor::colorationJavaScript()
{
     highlighter = new JavaScriptHighlighter(this->document());

     completion_text->setModelSorting(QCompleter::UnsortedModel);
     completion_text->setCaseSensitivity(Qt::CaseInsensitive);
     completion_text->setWrapAround(false);
     completion_text->setModel(modelFromFile(":/Resources/JavaScript.txt"));

     this->setCompleter(completion_text);
}

void CentralEditor::colorationPHP()
{
     highlighter = new PhpHighlighter(this->document());

     completion_text->setModelSorting(QCompleter::UnsortedModel);
     completion_text->setCaseSensitivity(Qt::CaseInsensitive);
     completion_text->setWrapAround(false);
     completion_text->setModel(modelFromFile(":/Resources/PHP.txt"));

     this->setCompleter(completion_text);
}
/*...............................................................................................................*/
