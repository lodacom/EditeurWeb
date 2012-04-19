#include "CompleterController.h"
#include "Views/CentralEditor.h"
#include <QCompleter>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QtDebug>
#include <QApplication>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>

CompleterController::CompleterController(QWidget *parent):QTextEdit(parent),completion_text(0)
{

}

CompleterController::~CompleterController()
{
}

/*void CompleterController::setCompleter(QCompleter *completer)
{
    CentralEditor *fen_central=new CentralEditor();

    if (completion_text)
        QObject::disconnect(completion_text, 0,fen_central, 0);//on déconnecte l'auto-compléteur de la fenêtre

    completion_text = completer;

    if (!completion_text)
        return;

    completion_text->setWidget(fen_central);//on met en place la completion
    completion_text->setCompletionMode(QCompleter::PopupCompletion);//mode de complétion
    completion_text->setCaseSensitivity(Qt::CaseInsensitive);//non prise en compte de la casse (majuscule, minuscule)
    QObject::connect(completion_text, SIGNAL(activated(QString)),fen_central, SLOT(insertCompletion(QString)));*/
   /* on connecte le compléteur à la fenêtre principale
      la complétion s'active sur lactivation du clavier
      et on fait l'action insertCompletion*/

//}

/*QCompleter *CompleterController::completer() const
{
    return completion_text;//on retourne tous les mots affiliés à ceux qu'on a trouvé
}*/

/*void CompleterController::insertCompletion(const QString& completion)
{

   if (completion_text->widget() != this)
        return;
    QTextCursor tc= textCursor();
    int extra = completion.length() - completion_text->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);//on met le curseur à la fin du mot complété
    tc.insertText(completion.right(extra));//complétion (rajout du reste du mot choisi)à droite
    setTextCursor(tc);//mise en place de la suivie du curseur
}*/

/*QString CompleterController::textUnderCursor() const
{
    QTextCursor tc= textCursor();
    tc.select(QTextCursor::WordUnderCursor);//on sélectionne le mot que l'utilisateur a choisi
    return tc.selectedText();//on renvoie le mot choisi par l'utilisateur
}*/

/*void CompleterController::focusInEvent(QFocusEvent *e)
{
    CentralEditor *fen_central=new CentralEditor;

    if (completion_text)//on regarde si la complétion est lancée
        completion_text->setWidget(fen_central);
    QTextEdit::focusInEvent(e);
}*/

/*void CompleterController::keyPressEvent(QKeyEvent *e)
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
    }*/

    /*Ci-dessous on met en place le rectangle avec srcoll bar qui apparaitra
      *lors de la complétion. On calcule sa lageur avec le plus long mot trouvé
      * et sa hauteur avec le nombre de mots trouvés*/
   /* QRect cr = cursorRect();
    cr.setWidth(completion_text->popup()->sizeHintForColumn(0)
                + completion_text->popup()->verticalScrollBar()->sizeHint().width());
    completion_text->complete(cr); // popup it up!
}*/
