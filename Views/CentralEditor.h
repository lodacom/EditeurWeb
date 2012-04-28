/*!
* \file CentralEditor.h
* \authors Olivier Mickael Joachim
* \version 0.2
*/
#include <QAbstractItemModel>
#include <QTextEdit>
#include <QFile>
#include <string>
#include <QCursor>
using namespace std;
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
#include "Controllers/IndenterController.h"

#ifndef CENTRALEDITOR_H
#define CENTRALEDITOR_H

/*!
* \class Centraleditor
* \brief Permet d'obtenir un onglet au centre de l'interface. Cet onglet
* possède les fonctionnalités d'auto-completion et de coloration syntaxique
* en fonction du langage choisi.
*/
class CentralEditor:public QTextEdit
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur
     * Création d'un onglet possédant les fonctionnalités citées
     * ci-dessus.
     * \param parent: l'onglet concerné par les fonctionnalités
     */
    CentralEditor(QWidget *parent = 0, string filePath = "", IndenterController *indentController = 0);

    /*!
     * \brief Mise en place des propriétés de l'éditeur.
     */
    void setupEditor();

    /*!
     * \brief Lancement de la complétion. Et connection de la fonctionnalité
     * à l'onglet qui est selectionné par l'utilisateur.
     * \param comp_edit: permet de récupérer les outils disponibles
     * qui ont été créés par Qt concernant la complétion.
     */
    void setCompleter(QCompleter *comp_edit);

    /*!
     * \brief
     * \return Un completeur.
     */
    QCompleter *completer() const;

    /*!
     * \brief Permet de créer un nouveau fichier avec un nom par défaut
     * (documentnb.txt nb étant le numéro de fichier non nommé)
     */
    void newFile();

    /*!
     * \brief Permet de charger le fichier ouvert par l'utilisateur.
     * \param On passe en paramètre le nom duc fichier
     * \return Vrai si le fichier a pu être chargé. Sinon faux.
     */
    bool loadFile(const QString &fileName);

    /*!
     * \brief Permet de sauvegarder le fichier courant qui a été édité
     * \return Vrai si le fichier a pu être chargé.Sinon faux.
     */
    bool save();

    /*!
     * \brief Permet de sauvegarder le fichier courant en tant que ...
     * L'utilisateur choisi donc le nom de fichier et extension qu'il
     * souhaite mettre au fichier.
     * \return Vrai si le fichier a été sauvegarder. Sinon faux.
     */
    bool saveAs();

    /*!
     * \brief Permet de mettre un nom au fichier sauvegardé.
     * \param On passe en paramètre le nom que l'utilisateur veut mettre.
     * \retun Vrai si on y a réussi. Faux sinon.
     */
    bool saveFile(const QString &fileName);

    /*!
     * \brief Permet de connaitre le nom de fichier.
     * \return Retourne le nom de ce dernier.
     */
    QString userFriendlyCurrentFile();

    QString currentFile() { return curFile; }
    QString currentLine();

public slots:
    /*!
     * \brief Permet de colorer en prenant en compte le langage CSS
     * définit dans la classe CSSHighlither et CSSData. Elle permet
     * également de lancer une complétion dans ce même langage.
     * Ces fonctionnalités sont connectés pour chaque onglet créé.
     */
    void colorationCSS();

    /*!
     * \brief Permet de colorer en prenant en compte le langage HTML
     * définit dans la classe HtmlHighlither et HtmlData. Elle permet
     * également de lancer une complétion dans ce même langage.
     * Ces fonctionnalités sont connectés pour chaque onglet créé.
     */
    void colorationHTML();

    /*!
     * \brief Permet de colorer en prenant en compte le langage Java Script
     * définit dans la classe JavaScriptHighlither et JavaScriptData. Elle permet
     * également de lancer une complétion dans ce même langage.
     * Ces fonctionnalités sont connectés pour chaque onglet créé.
     */
    void colorationJavaScript();

    /*!
     * \brief Permet de colorer en prenant en compte le langage PHP
     * définit dans la classe PhpHighlither et PhpData. Elle permet
     * également de lancer une complétion dans ce même langage.
     * Ces fonctionnalités sont connectés pour chaque onglet créé.
     */
    void colorationPHP();

    /*!
     * \brief Permet d'insérer le mot choisi par l'utilisateur et de
     * déplacer le curseur à la fin du mot complété.
     */
    void insertCompletion(const QString& completion);

    /*!
     * \brief Permet de savoir si un fichier a été modifié.
     */
    void documentWasModified();
    void indentCheck();
protected:
    /*!
     * \brief Permet d'afficher au fur et à mesure de la frappe de
     * l'utilisateur les propositions disponibles dans le dictionnaire
     * des données correspondant au langage choisi par l'utilisateur.
     * Les propositions s'effectuent à partir de la frappe d'une seule
     * lettre.
     * \param e:permet de récupérer les touches frappées par l'utilisateur
     */
    void keyPressEvent(QKeyEvent *e);

    /*!
     * \brief
     * \param e
     */
    void focusInEvent(QFocusEvent *e);

    /*!
     * \brief Dit quoi faire lors de la fermeture d'un onglet.
     * Exemple: si le fichier doit être sauvegardé (en regardant
     * s'il a été modifié ou non).
     */
    void closeEvent(QCloseEvent *event);

private:
    //CompleterController *completerController;
    QCompleter *completion_text;
    QString textUnderCursor() const;

    Highlighter *highlighter;
    QAbstractItemModel *modelFromFile(const QString& fileName);

    /*!
     * \brief Permet de savoir si le fichier doit être sauvegardé
     * ou non selon s'il a été modifier ou non.
     * \return Vrai si le fichier doit être sauvegardé. Faux sinon.
     */
    bool maybeSave();

    /*!
     * \brief Change le titre du fichier pour montrer à l'utilisateur
     * que ce dernier a été modifié.
     * \param On passe en paramètre le nom du fichier
     */
    void setCurrentFile(const QString &fileName);

    /*!
     * \brief Récupère le nom du fichier
     * \param On passe en paramètre le nom du fichier
     * \return On retourne le nom du fichier
     */
    QString strippedName(const QString &fullFileName);
    int countTab();
    string filePath;
    QString curFile;
    bool isUntitled;
    bool newLine;
    bool addTabs;
    bool newTab;
    int tabNumber;
    IndenterController *indentController;

private slots:
    void indent();
};

#endif // CENTRALEDITOR_H
