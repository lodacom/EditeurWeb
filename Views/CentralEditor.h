/*#include <QWidget>
#include <QStringListModel>
#include <QCompleter>
#include <QFile>
#include <QApplication>*/
#include <QAbstractItemModel>
#include <QTextEdit>
#include <QFile>
#include <string>
QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE

//#include "Controllers/CompleterController.h"
#include "Controllers/Highlighting/Highlighter.h"
#include "Controllers/Highlighting/CSSHighlighter.h"
#include "Controllers/Highlighting/HtmlHighlighter.h"
#include "Controllers/Highlighting/JavaScriptHighlighter.h"
#include "Controllers/Highlighting/PhpHighlighter.h"
#include "Tools/Tools.h"
using namespace std;
#ifndef CENTRALEDITOR_H
#define CENTRALEDITOR_H

class CentralEditor:public QTextEdit
{
    Q_OBJECT

public:
    CentralEditor(QWidget *parent = 0, string filePath = "");
    void setupEditor();
    void setCompleter(QCompleter *c);
    QCompleter *completer() const;

public slots:
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();
    void insertCompletion(const QString& completion);

protected:
    void keyPressEvent(QKeyEvent *e);
    void focusInEvent(QFocusEvent *e);

private:
    //CompleterController *completerController;
    QCompleter *completion_text;
    QString textUnderCursor() const;
    string filePath;
    Highlighter *highlighter;
    QAbstractItemModel *modelFromFile(const QString& fileName);

};

#endif // CENTRALEDITOR_H
