#include <QWidget>
#include <QStringListModel>
#include <QCompleter>
#include <QFile>
#include <QMenu>
#include <QApplication>

#include "Controllers/CompleterController.h"
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

public slots:
    void colorationCSS();
    void colorationHTML();
    void colorationJavaScript();
    void colorationPHP();

private:
    //QStringListModel* updateListVar();
    CompleterController *completerController;
    Highlighter *highlighter;
    //QAbstractItemModel *modelFromFile(const QString& fileName);
};

#endif // CENTRALEDITOR_H
