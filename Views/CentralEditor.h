/*#include <QWidget>
#include <QStringListModel>
#include <QCompleter>
#include <QFile>
#include <QApplication>*/
#include <QAbstractItemModel>
#include <QTextEdit>
#include <QFile>

QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE

//#include "Controllers/CompleterController.h"
#include "Controllers/Highlighting/Highlighter.h"
#include "Controllers/Highlighting/CSSHighlighter.h"
#include "Controllers/Highlighting/HtmlHighlighter.h"
#include "Controllers/Highlighting/JavaScriptHighlighter.h"
#include "Controllers/Highlighting/PhpHighlighter.h"
#ifndef CENTRALEDITOR_H
#define CENTRALEDITOR_H

class CentralEditor:public QTextEdit
{
    Q_OBJECT

public:
    CentralEditor(QWidget *parent = 0);
    void setupEditor();
    void setCompleter(QCompleter *c);
    QCompleter *completer() const;

    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendlyCurrentFile();
    QString currentFile() { return curFile; }

public slots:
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();
    void insertCompletion(const QString& completion);
    void documentWasModified();

protected:
    void keyPressEvent(QKeyEvent *e);
    void focusInEvent(QFocusEvent *e);
     void closeEvent(QCloseEvent *event);

private:
    //CompleterController *completerController;
    QCompleter *completion_text;
    QString textUnderCursor() const;

    Highlighter *highlighter;
    QAbstractItemModel *modelFromFile(const QString& fileName);

    bool maybeSave();
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;
};

#endif // CENTRALEDITOR_H
