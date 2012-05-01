#include "CentralEditor.h"
#include <QtGui>
#include <QCompleter>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QtDebug>
#include <QApplication>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>
#include <QStringListModel>
#include <iostream>

using namespace std;
CentralEditor::CentralEditor(QWidget *parent, string filePath, IndenterController *indentController):QTextEdit(parent),completion_text(0)
{
    completion_text = new QCompleter(this);
    this->filePath = filePath;
    this->indentController = indentController;
    addTabs = false;
    newTab = false;
    this->setTabStopWidth(20);
    setupEditor();
    QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(checkLanguage()));
    QObject::connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(indent()));
}

void CentralEditor::setupEditor()
{
    QFont font;
    string extension = Tools::getExtension(filePath);
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);
    this->setFont(font);

   if (extension == "php"){
    colorationPHP();
   }
   else if(extension == "html" || extension == "htm"){
   colorationHTML();
   }
   else if(extension == "css"){
        colorationCSS();
   }
   else if(extension == "js"){
        colorationJavaScript();
   }
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
    if(e->key() == Qt::Key_Return && !completion_text->popup()->isVisible()){
        indentCheck();
    }

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
/*Partie gestion sauvegarde, création... pour les fichiers*/
void CentralEditor::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;
    curFile = tr("document%1.txt").arg(sequenceNumber++);
    setWindowTitle(curFile + "[*]");

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));
}

bool CentralEditor::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    return true;
}

bool CentralEditor::save()
{
    if (isUntitled)
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool CentralEditor::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool CentralEditor::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

QString CentralEditor::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}

void CentralEditor::closeEvent(QCloseEvent *event)
{
    if (maybeSave())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void CentralEditor::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool CentralEditor::maybeSave()
{
    if (document()->isModified())
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("MDI"),
                     tr("'%1' has been modified.\n"
                        "Do you want to save your changes?")
                     .arg(userFriendlyCurrentFile()),
                     QMessageBox::Save | QMessageBox::Discard
                     | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void CentralEditor::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString CentralEditor::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

QString CentralEditor::currentLine(){
    QTextCursor cursor = textCursor();
    return cursor.block().text().trimmed();
}

QString CentralEditor::previousLine(){
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::PreviousBlock);
    return cursor.block().text().trimmed();
}

void CentralEditor::indentCheck(){
    QTextCursor cursor = textCursor();
    int indentResult = indentController->indentDetermin(currentLine());
    int previousLineTabNb;
    int currentLineTabNb;
    switch(indentResult){
    case 1:
        newTab = true;
        break;
    case -1:
        previousLineTabNb = countPreviousLineTab();
        currentLineTabNb = countCurrentLineTab();
        if(previousLineTabNb < currentLineTabNb){
                cursor.movePosition(QTextCursor::StartOfBlock);
                for (int i = 0; i < currentLineTabNb - previousLineTabNb; i++)
                    cursor.deleteChar();
                cursor.movePosition(QTextCursor::EndOfBlock);
                this->setTextCursor(cursor);
        }
        else if(previousLineTabNb == currentLineTabNb){
            if(indentController->indentDetermin(previousLine()) == -1){
                cursor.movePosition(QTextCursor::StartOfBlock);
                cursor.deleteChar();
                cursor.movePosition(QTextCursor::EndOfBlock);
                this->setTextCursor(cursor);
            }
        }
        break;
    default:
        break;
    }
    addTabs = true;
}

void CentralEditor::indent(){
    if(addTabs){
        addTabs = false;
        QTextCursor cursor = textCursor();
        QString tab = QString('\t');
        int tabNumb = countPreviousLineTab();
        if(newTab){
            tabNumb++;
            newTab = false;
        }
        for (int i = 0; i < tabNumb; i++){
            cursor.insertText(tab);
        }
        this->setTextCursor(cursor);
    }
}

int CentralEditor::countPreviousLineTab(){
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::PreviousBlock);
    int i = 0;
    while(cursor.block().text().at(i) == '\t'){
        i++;
    }
    return i;
}
int CentralEditor::countCurrentLineTab(){
    QTextCursor cursor = textCursor();
    int i = 0;
    while(cursor.block().text().at(i) == '\t'){
        i++;
    }
    return i;
}
void CentralEditor::checkLanguage(){
    QTextCursor cursor = textCursor();
    QString line = cursor.block().text().trimmed();
    bool cont = true;
    if(line.contains("<?php")){
        indentController->setLanguage(PHP_LANGUAGE);
        colorationPHP();
        cont = false;
    }
    else if(line.contains("<")){
        indentController->setLanguage(HTML_LANGUAGE);
        colorationHTML();
        cont = false;
    }
    else{
        if(cursor.blockNumber() != 0){
            cursor.movePosition(QTextCursor::PreviousBlock);
            line = cursor.block().text().trimmed();
        }
        else{
            cont = false;
            indentController->setLanguage(UNKNOWN_LANGUAGE);
        }
    }
    while(cont){
        if(line.contains("<?php")){
            indentController->setLanguage(PHP_LANGUAGE);
            colorationPHP();
            cont = false;
        }
        else if(line.contains("<") || line.contains("?>")){
            indentController->setLanguage(HTML_LANGUAGE);
            colorationHTML();
            cont = false;
        }
        else{
            if(cursor.blockNumber() != 0){
                cursor.movePosition(QTextCursor::PreviousBlock);
                line = cursor.block().text().trimmed();
            }
            else{
                cont = false;
                indentController->setLanguage(UNKNOWN_LANGUAGE);
            }
        }
    }
}
