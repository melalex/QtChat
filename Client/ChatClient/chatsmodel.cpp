#include "chatsmodel.h"
#include "model.h"
#include "group.h"
#include "user.h"

const quint8 kColumnCount = 2;

//ChatsModel

ChatsModel::ChatsModel(Model *model, QObject *parent) :
    QAbstractTableModel(parent)
{
    _model = model;

    for (Group *group: *_model->chats())
    {
        _tableModel.append(new RowViewModel(group));
    }
}

ChatsModel::~ChatsModel()
{
    qDeleteAll(_tableModel);
}

QList<quint16> *ChatsModel::selectedItems()
{
    QList<quint16> *result = new QList<quint16>();

    for (quint16 i = 0; i < _tableModel.count(); i++)
    {
        if (_tableModel[i]->isChecked())
        {
            result->append(i);
            _tableModel[i]->unCheck();
        }
    }

    return result;
}

Qt::ItemFlags ChatsModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags result = QAbstractTableModel::flags(index);

    if(index.column() == 1)
    {
        result = result | Qt::ItemIsUserCheckable;
    }

    return result;
}

int ChatsModel::rowCount(const QModelIndex &parent) const
{
    return _tableModel.count();
}

int ChatsModel::columnCount(const QModelIndex &parent) const
{
    return kColumnCount;
}

QVariant ChatsModel::data(const QModelIndex &index, int role) const
{
    QVariant result;

    if (role == Qt::DisplayRole && index.column() == 0)
    {
        result = QVariant(_tableModel.at(index.row())->login());
    }
    else if (role == Qt::CheckStateRole && index.column() == 1)
    {
        result = _tableModel.at(index.row())->isChecked() ? Qt::Checked : Qt::Unchecked;
    }
    else
    {
        result = QVariant();
    }

    return result;
}

bool ChatsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool result = false;

    if (index.isValid() && role == Qt::CheckStateRole)
    {
        if ((Qt::CheckState)value.toInt() == Qt::Checked)
        {
            _tableModel.at(index.row())->check();
            result = true;
        }
        else
        {
            _tableModel.at(index.row())->unCheck();
            result = true;
        }
    }

    return result;
}

//RowViewModel

RowViewModel::RowViewModel(Group *group)
{
    _login = group->getName();
    _checkBox = false;
}

QString RowViewModel::login()
{
    return _login;
}

bool RowViewModel::isChecked()
{
    return _checkBox;
}

void RowViewModel::check()
{
    _checkBox = true;
}

void RowViewModel::unCheck()
{
    _checkBox = false;
}
