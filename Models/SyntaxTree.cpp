#include <QtGui>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>

#include "SyntaxTree.h"
#include "SyntaxTreeItem.h"
#include "HtmlData.h"

//! [0]
SyntaxTree::SyntaxTree(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Nom bloc" << "NumLigne";
    rootItem = new SyntaxTreeItem(rootData);
    setupModelData(data.split(QString("\n")), rootItem);
}
//! [0]

//! [1]
SyntaxTree::~SyntaxTree()
{
    delete rootItem;
}
//! [1]

//! [2]
int SyntaxTree::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<SyntaxTreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}
//! [2]

//! [3]
QVariant SyntaxTree::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    SyntaxTreeItem *item = static_cast<SyntaxTreeItem*>(index.internalPointer());

    return item->data(index.column());
}
//! [3]

//! [4]
Qt::ItemFlags SyntaxTree::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
//! [4]

//! [5]
QVariant SyntaxTree::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
//! [5]

//! [6]
QModelIndex SyntaxTree::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    SyntaxTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<SyntaxTreeItem*>(parent.internalPointer());

    SyntaxTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}
//! [6]

//! [7]
QModelIndex SyntaxTree::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    SyntaxTreeItem *childItem = static_cast<SyntaxTreeItem*>(index.internalPointer());
    SyntaxTreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
//! [7]

//! [8]
int SyntaxTree::rowCount(const QModelIndex &parent) const
{
    SyntaxTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<SyntaxTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}
//! [8]

void SyntaxTree::setupModelData(const QStringList &lines, SyntaxTreeItem *parent)
{
    QList<SyntaxTreeItem*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;
    while (number < lines.count())
    {
        // Supprime les espaces blancs au début et à la fin de la ligne.
        QString lineData = lines[number].trimmed();

        if (!lineData.isEmpty())
        {
            QList<QVariant> newNode;

            QRegExp expOpenTag = HtmlData::tagOpenBeginRegex;
            QRegExp expCloseTag = HtmlData::tagCloseRegex;
            int index1 = expOpenTag.indexIn(lineData);
            int index2 = expCloseTag.indexIn(lineData);

            while (index1 >= 0 or index2 >= 0)
            {
                newNode.clear();
                if(index2 < index1)
                {
                    QMessageBox msgBox;
                    QStringList t = expOpenTag.capturedTexts();
                    t << QString::number(index1) << QString::number(index2);
                    msgBox.setText(t.join(""));
                    msgBox.exec();
                    newNode << expOpenTag.capturedTexts() << number + 1;
                    if (!parents.isEmpty())
                    {
                        if (parents.last()->childCount() > 0)
                        {
                            parents << parents.last()->child(parents.last()->childCount()-1);
                        }

                        if (!newNode.isEmpty())
                        {
                            parents.last()->appendChild(new SyntaxTreeItem(newNode, parents.last()));
                            newNode.clear();
                        }
                    }
                    else
                    {
                        parent->appendChild(new SyntaxTreeItem(newNode, parent));
                    }
                    int len = expOpenTag.matchedLength();
                    index1 = expOpenTag.indexIn(lineData, index1 + len);
                    index2 = expCloseTag.indexIn(lineData, index1 + len);
               }
               else
               {
                    if(!parents.isEmpty())
                        parents.pop_back();
                    int len = expCloseTag.matchedLength();
                    index1 = expOpenTag.indexIn(lineData, index2 + len);
                    index2 = expCloseTag.indexIn(lineData, index2 + len);
               }
            }
        }
        number++;
    }
}
