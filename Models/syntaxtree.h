#ifndef SYNTAXTREE_H
#define SYNTAXTREE_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

class SyntaxTreeItem;

//! [0]
class SyntaxTree : public QAbstractItemModel
{
    Q_OBJECT

public:
    SyntaxTree(const QString &data, QObject *parent = 0);
    ~SyntaxTree();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
    void setupModelData(const QStringList &lines, SyntaxTreeItem *parent);

    SyntaxTreeItem *rootItem;
};
//! [0]

#endif // SYNTAXTREE_H
