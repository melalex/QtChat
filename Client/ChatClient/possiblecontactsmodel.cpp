#include "possiblecontactsmodel.h"
#include "user.h"

#include <QList>

const quint8 kColumnCount = 1;

PossibleContactsModel::PossibleContactsModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

PossibleContactsModel::~PossibleContactsModel()
{

}

void PossibleContactsModel::clear()
{
    if (rowCount() > 0)
    {
        removeRows(0, rowCount());
    }
}

int PossibleContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return _tableModel.count();
}

int PossibleContactsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return kColumnCount;
}

bool PossibleContactsModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

QVariant PossibleContactsModel::data(const QModelIndex &index, int role) const
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

bool PossibleContactsModel::insertRows(int row, int count, const QModelIndex &parent)
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

bool PossibleContactsModel::removeRows(int row, int count, const QModelIndex &parent)
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

void PossibleContactsModel::setPossibleContacts(QList<User *> *users)
{
    clear();

    insertRows(0, users->count());

    for (int i = 0; i < users->count(); i++)
    {
        setData(createIndex(i, 0), users->at(i)->getLogin());
    }
}
