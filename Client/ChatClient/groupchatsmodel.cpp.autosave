#include "groupchatsmodel.h"
#include "model.h"
#include "group.h"

#include <QList>

const quint8 kColumnCount = 1;

GroupChatsModel::GroupChatsModel(Model *model, QObject *parent) :
    QAbstractTableModel(parent), _model(model)
{

    for (Group *group: *_model->groupChats())
    {
        _tableModel.append(group->getName());
    }

    connect(_model, SIGNAL(groupChatAdded(Group*)), this, SLOT(groupChatAdded(Group*)));
    connect(_model, SIGNAL(groupChatRemoved(quint16)), this, SLOT(groupChatRemoved(quint16)));
}

GroupChatsModel::~GroupChatsModel()
{

}

void GroupChatsModel::clear()
{
    removeRows(0, rowCount());
}

int GroupChatsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return _tableModel.count();
}

int GroupChatsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return kColumnCount;
}

bool GroupChatsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool result = false;

    if (index.isValid() && index.column() == 0 && role == Qt::EditRole)
    {
        _tableModel.replace(index.row(), value.toString());

        emit dataChanged(index, index);

        result = true;
    }

    return result;
}

QVariant GroupChatsModel::data(const QModelIndex &index, int role) const
{
    QVariant result;

    if (role == Qt::DisplayRole && index.column() == 0)
    {
        result = QVariant(_tableModel.at(index.row()));
    }
    else
    {
        result = QVariant();
    }

    return result;

}

bool GroupChatsModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; i++)
    {
        _tableModel.insert(row, "");
    }

    endInsertRows();

    return true;
}

bool GroupChatsModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    beginRemoveRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; i++)
    {
        _tableModel.removeAt(row);
    }

    endRemoveRows();

    return true;
}

void GroupChatsModel::groupChatAdded(Group *chat)
{
    insertRow(rowCount());

    setData(createIndex(rowCount() - 1, 0), chat->getName());
}

void GroupChatsModel::groupChatRemoved(quint16 index)
{
    removeRow(index);
}
