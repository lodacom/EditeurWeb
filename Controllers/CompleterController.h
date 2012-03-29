#include <QTextEdit>
#include <QString>
#include <QAbstractItemModel>
#include <QFile>
#include <QStringListModel>
#include <string>
#include <QApplication>
#include <QCompleter>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QScrollBar>
#include <QtGui>
QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE

#ifndef COMPLETION_H
#define COMPLETION_H

class CompleterController
{


public:
    CompleterController();
    ~CompleterController();

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;
/*
protected:
    void keyPressEvent(QKeyEvent *e);
    void focusInEvent(QFocusEvent *e);

private slots:
    void insertCompletion(const QString &completion);

private:
    QString textUnderCursor() const;
*/
private:
    QCompleter *completion_text;
};

#endif // COMPLETION_H
