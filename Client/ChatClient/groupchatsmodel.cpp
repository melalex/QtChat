#include "groupchatsmodel.h"
#include "model.h"
#include "group.h"

#include <QList>

const quint8 kColumnCount = 1;

GroupChatsModel::GroupChatsModel(Model *model, QObject *parent) :
    QAbstractTableModel(parent), _model(model)
{

}

GroupChatsModel::~GroupChatsModel()
{

}

int GroupChatsModel::rowCount(const QModelIndex &parent) const
{
    return _model->groupChats()->count();
}

int GroupChatsModel::columnCount(const QModelIndex &parent) const
{
    return kColumnCount;
}

QVariant GroupChatsModel::data(const QModelIndex &index, int role) const
{
    QVariant result;

    if (role == Qt::DisplayRole && index.column() == 0)
    {
        result = QVariant(_model->groupChats()->at(index.row())->getName());
    }
    else
    {
        result = QVariant();
    }

    return result;

}
