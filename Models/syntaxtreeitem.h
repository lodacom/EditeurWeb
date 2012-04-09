#ifndef SYNTAXTREEITEM_H
#define SYNTAXTREEITEM_H

#include <QList>
#include <QVariant>

//! [0]
class SyntaxTreeItem
{
public:
    SyntaxTreeItem(const QList<QVariant> &data, SyntaxTreeItem *parent = 0);
    ~SyntaxTreeItem();

    void appendChild(SyntaxTreeItem *child);

    SyntaxTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    SyntaxTreeItem *parent();

private:
    QList<SyntaxTreeItem*> childItems;
    QList<QVariant> itemData;
    SyntaxTreeItem *parentItem;
};
//! [0]

#endif
