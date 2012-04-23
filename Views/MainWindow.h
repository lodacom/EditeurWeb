/*!
 * \file MainWindow.h
 * \authors Olivier Mickael Joachim
 * \version 0.2
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QApplication>

#include "../Controllers/Highlighting/JavaScriptHighlighter.h"
#include "../Controllers/Highlighting/HtmlHighlighter.h"
#include "../Controllers/Highlighting/CSSHighlighter.h"
#include "../Controllers/Highlighting/PhpHighlighter.h"
#include "CentralEditor.h"
#include "../Controllers/WorkSpaceTreeController.h"
#include "HtmlTreeWidget.h"
#include "WorkSpaceTree.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QTextEdit;
class QTreeWidgetItem;
class QWebView;
class QTreeWidget;
QT_END_NAMESPACE

/*!
* \class MainWindow
* \brief Permet d'obtenir toute l'interface utilisateur avec son
* menu, son dock, et ses actions correspondantes.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur
     * Création de la fenêtre principale contenant toute l'interface.
     * \param parent: la fenêtre concernée par toutes les actions de
     * l'utilisateur.
     */
    MainWindow(QWidget *parent = 0);
    //MainWindow(const QString &fileName);

public slots:
    /*!
     * \brief Permet d'ouvrir un fichier dans un nouvel onglet
     */
    void open();

    /*!
     * \brief Permet de sauvegarder l'onglet actif
     */
    void save();

    /*!
     * \brief Permet de sauvegarder en tant que l'onglet actif
     */
    void saveAs();

    /*!
     * \brief Enclenche l'action couper sur l'onglet courant
     */
    void cut();

    /*!
     * \brief Enclenche l'action copier sur l'onglet courant
     */
    void copy();

    /*!
     * \brief Enclenche l'action coller sur l'onglet courant
     */
    void paste();

    /*!
     * \brief Enclenche l'action annuler sur l'onglet courant
     */
    void undo();

    /*!
     * \brief Enclenche l'action refaire sur l'onglet courant
     */
    void redo();

    /*!
     * \brief Enclenche l'action tout sélectionner sur l'onglet courant
     */
    void selectAll();

    /*!
     */
    void updateWindowMenu();

    /*!
     * \brief Met à jour la bar de menu en fonction de la
     * présence ou non de fenêtre(s) au centre de l'interface.
     */
    void updateMenus();

    /*!
     * \brief Crée un fils de type CentralEditor et l'ajoute au centre
     * de l'interface.
     * \return Un onglet de type CentralEditor.
     */
    CentralEditor *createMdiChild();

    /*!
     * \brief Met à "vrai" la fenêtre qui a été modifiée et indique
     * ainsi que le document concerné l'est également
     */
    void documentWasModified();

    /*!
     * \brief Change la façon d'afficher pour les fenêtres.
     */
    void switchLayoutDirection();


    void setActiveSubWindow(QWidget *window);
    void about();
    void newFile();
    //void openFile(const QString &path = QString());
    void selectWorkSpace();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void init();
    void setupWorkSpaceDock();
    //void setupHtmlDock();

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void createVboxlayout();
    void writeSettings();

    CentralEditor *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);

    QString strippedName(const QString &fullFileName);
    WorkSpaceTree *treeView;
    HtmlTreeWidget *htmlTreeWidget;

    QMdiArea *zoneCentrale;
    QSignalMapper *windowMapper;

    QMenu *menuColoration;
    QMenu *windowMenu;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionPHP;
    QAction *actionCSS;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *closeAct;
    QAction *closeAllAct;
    QAction *tileAct;
    QAction *cascadeAct;
    QAction *nextAct;
    QAction *previousAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *selectallAct;
    QAction *separatorAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
