#include "HtmlTreeWidget.h"
#include "ui_htmltreewidget.h"

#include <QtGui>
#include <QtWebKit>

HtmlTreeWidget::HtmlTreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HtmlTreeWidget)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl("file:///users/Abdelhamid/Downloads/p.html"));
    ui->webView->setZoomFactor(0.3);
    this->setMaximumWidth(400);
}

void HtmlTreeWidget::setUrl(const QUrl &url)
{
    ui->webView->setUrl(url);
}

void HtmlTreeWidget::on_webView_loadFinished()
{
    ui->treeWidget->clear();

    QWebFrame *frame = ui->webView->page()->mainFrame();
    QWebElement document = frame->documentElement();

    examineChildElements(document, ui->treeWidget->invisibleRootItem());
}

void HtmlTreeWidget::examineChildElements(const QWebElement &parentElement,
                                  QTreeWidgetItem *parentItem)
{
    QWebElement element = parentElement.firstChild();
    while (!element.isNull())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, element.tagName());
        parentItem->addChild(item);

        examineChildElements(element, item);

        element = element.nextSibling();
    }
}

HtmlTreeWidget::~HtmlTreeWidget()
{
    delete ui;
}
