/*!
* \file HtmlTreeWidget.h
* \brief Déclaration de la classe graphique pour le panneau de droite.
* \author Abdelhamid
* \version 0.1
*/
#ifndef HTMLTREEWIDGET_H
#define HTMLTREEWIDGET_H

#include <QWidget>
#include <QWebElement>

QT_BEGIN_NAMESPACE
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace Ui {
class HtmlTreeWidget;
}

/*!
* \class HtmlTreeWidget
* \brief Classe graphique générée par QtDesigner
*/
class HtmlTreeWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur
     * Création du widget avec une QWebView et un QTreeWidget intégrés.
     * \param parent: le QWidget aui integrera la vue.
     */
    explicit HtmlTreeWidget(QWidget *parent = 0);

    /*!
     * \brief Changer l'url de la webview.
     * \param url: la nouvelle url.
     */
    void setUrl(const QUrl &url);
    ~HtmlTreeWidget();

public slots:
    /*!
     * \brief Définit les actions à réaliser lorsque la webview est
     totalement chargée.
     */
    void on_webView_loadFinished();

private:
    /*!
     * \brief Construit une arborescence en analysant un QWebElement.
     * \param parentElement: la racine du QWebElement à analyser.
     * \param parentItem: la racine du nouvel arbre.
     */
    void examineChildElements(const QWebElement &parentElement,
                              QTreeWidgetItem *parentItem);
    Ui::HtmlTreeWidget *ui;
};
#endif // HTMLTREEWIDGET_H
