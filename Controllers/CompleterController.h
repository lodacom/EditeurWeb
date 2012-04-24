/*!
* \file CompleterController.h
* \brief Fichier concernant l'auto-complétion
* \author Olivier
* \version 0.1
*/

#ifndef COMPLETION_H
#define COMPLETION_H

#include <QTextEdit>
//#include <Views/CentralEditor.h>

QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE

/*!
* \class CompleterController
* \brief Contient uniquement le constructeur et le destructeur
* de l'auto-compléteur
*/

class CompleterController: public QTextEdit
{
 Q_OBJECT

public:
    CompleterController(QWidget *parent = 0);
    ~CompleterController();

    //void setCompleter(QCompleter *c);
    //QCompleter *completer() const;
    //void keyPressEvent(QKeyEvent *e);

    //void focusInEvent(QFocusEvent *e);

private slots:
    //void insertCompletion(const QString &completion);

private:
   // QString textUnderCursor() const;
    QCompleter *completion_text;
};

#endif // COMPLETION_H
