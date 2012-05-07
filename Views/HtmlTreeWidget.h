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

class HtmlTreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HtmlTreeWidget(QWidget *parent = 0);
    void setUrl(const QUrl &url);
    ~HtmlTreeWidget();

public slots:
    void on_webView_loadFinished();

private:
    void examineChildElements(const QWebElement &parentElement,
                              QTreeWidgetItem *parentItem);
    Ui::HtmlTreeWidget *ui;
};
#endif // HTMLTREEWIDGET_H
