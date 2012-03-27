#include <QTextEdit>
#include <QStringListModel>
#include <QCompleter>
#include <QFile>
#include <QMenu>
#include <QApplication>

#include "../Controllers/JavaScriptHighlighter.h"
#include "../Controllers/HtmlHighlighter.h"
#include "../Controllers/CSSHighlighter.h"
#include "../Controllers/PhpHighlighter.h"
#include "Controllers/completion.h"

#ifndef CENTRALEDITOR_H
#define CENTRALEDITOR_H

class CentralEditor:public QTextEdit
{
    Q_OBJECT

public:
    CentralEditor(QWidget *parent = 0);
    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionPHP;
    QAction *actionCSS;

public slots:
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();
    void setupColoration(QMenu *);

private:
    void setupEditor();
    QStringListModel* updateListVar();
    Completion *editor;
    Highlighter *highlighter;

    //QMenu *menuColoration;

    QCompleter *completer;
    QAbstractItemModel *modelFromFile(const QString& fileName);
};

#endif // CENTRALEDITOR_H
