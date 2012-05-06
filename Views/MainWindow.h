/*!
 * \file MainWindow.h
 * \authors Olivier Mickael Joachim Hamza
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
#include "EditorTab.h"
#include "WorkSpaceTree.h"
#include "Controllers/IndenterController.h"
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
    void createMdiChild(CentralEditor *child);
    /*!
     * \brief Met à "vrai" la fenêtre qui a été modifiée et indique
     * ainsi que le document concerné l'est également
     */
    void documentWasModified();

    /*!
     * \brief Change la façon d'afficher pour les fenêtres.
     */
    void switchLayoutDirection();

    /*!
     * \brief Rend actif l'onglet si il ne l'est pas.
     * \param window:On passe en paramètre la fenêtre à activer.
     */
    void setActiveSubWindow(QWidget *window);

    /*!
     * \brief Renseigne à propos du programme.
     */
    void about();

    /*!
     * \brief Crée un nouveau fichier en déclenchant la création
     * d'un nouveau fils et en le montrant à l'utilisateur.
     */
    void newFile();
    void openFile(const QString &path = QString());
    void selectWorkSpace();

protected:
    /*!
     * \brief Donne ce qui il y a à faire lors de la fermeture
     * de la fenêtre principale.
     * param: event récupère l'évènement de fermeture de la part
     * de l'utilisateur.
     */
    void closeEvent(QCloseEvent *event);

private:
    /*!
     * \brief Initialise tout ce qu'il va y avoir à l'interieur
     * de la fenêtre principale.
     */
    void init();
    void setupWorkSpaceDock();
    //void setupHtmlDock();

    /*!
     * \brief Crée toutes les actions dont à besoin l'utilisateur
     * pour effectuer des opérations sur l'interface.
     */
    void createActions();

    /*!
     * \brief Crée toute la barre de menu
     */
    void createMenus();

    /*!
     * \brief Crée toute la barre d'outils (plus rapide
     * pour l'utilisateur et plus agréable, images supplémentaires).
     */
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void createVboxlayout();
    void writeSettings();

    /*!
     * \brief Permet de connaître quel est l'onglet qui est actif dans
     * fenêtre.
     * \return L'onglet actif. Sinon rien s'il n'y a aucun onglet présent.
     */
    CentralEditor *activeMdiChild();

    /*!
     * \brief Permet de chercher une fenêtre/un onglet par son nom
     * \return La sous-fenêtre correspondante à se nom. Sinon rien
     * si aucune sous-fenêtre ne correspond.
     */
    QMdiSubWindow *findMdiChild(const QString &fileName);

    //QString strippedName(const QString &fullFileName);
    WorkSpaceTree *treeView;
    IndenterController *indenterController;
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
