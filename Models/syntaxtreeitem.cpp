#include "syntaxtreeitem.h"

#include <QStringList>

//! [0]
SyntaxTreeItem::SyntaxTreeItem(const QList<QVariant> &data, SyntaxTreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}
//! [0]

//! [1]
SyntaxTreeItem::~SyntaxTreeItem()
{
    qDeleteAll(childItems);
}
//! [1]

//! [2]
void SyntaxTreeItem::appendChild(SyntaxTreeItem *item)
{
    childItems.append(item);
}
//! [2]

//! [3]
SyntaxTreeItem *SyntaxTreeItem::child(int row)
{
    return childItems.value(row);
}
//! [3]

//! [4]
int SyntaxTreeItem::childCount() const
{
    return childItems.count();
}
//! [4]

//! [5]
int SyntaxTreeItem::columnCount() const
{
    return itemData.count();
}
//! [5]

//! [6]
QVariant SyntaxTreeItem::data(int column) const
{
    return itemData.value(column);
}
//! [6]

//! [7]
SyntaxTreeItem *SyntaxTreeItem::parent()
{
    return parentItem;
}
//! [7]

//! [8]
int SyntaxTreeItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<SyntaxTreeItem*>(this));

    return 0;
}
//! [8]
