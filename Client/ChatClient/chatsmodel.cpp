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
    
    connect(_model, SIGNAL(chatAdded(Group*)), this, SLOT(chatAdded(Group*)));
    connect(_model, SIGNAL(chatRemoved(quint16)), this, SLOT(chatRemoved(quint16)));
}

ChatsModel::~ChatsModel()
{
    qDeleteAll(_tableModel);
}

QList<quint16> *ChatsModel::selectedItems() const
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
    Q_UNUSED(parent);

    return _tableModel.count();
}

int ChatsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

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
    else if (index.isValid() && role == Qt::EditRole)
    {
        RowViewModel *rowViewModel = _tableModel.at(index.row());

        _tableModel.replace(index.row(), new RowViewModel(value.toString()));

        emit dataChanged(index, index);

        result = true;

        delete rowViewModel;
    }

    return result;
}

bool ChatsModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; i++)
    {
        _tableModel.insert(row, new RowViewModel());
    }

    endInsertRows();

    return true;
}

bool ChatsModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    beginRemoveRows(QModelIndex(), row, row + count - 1);

    RowViewModel *rowViewModel = nullptr;
    for (int i = 0; i < count; i++)
    {
        rowViewModel = _tableModel.at(row);

        _tableModel.removeAt(row);

        delete rowViewModel;
    }

    endRemoveRows();

    return true;
}

void ChatsModel::chatAdded(Group *chat)
{
    insertRow(rowCount());

    setData(createIndex(rowCount() - 1, 0), chat->getName());
}

void ChatsModel::chatRemoved(quint16 index)
{
    removeRow(index);
}

//RowViewModel

RowViewModel::RowViewModel() :
    _login(""), _checkBox(false)
{

}

RowViewModel::RowViewModel(QString login) :
    _login(login), _checkBox(false)
{

}

RowViewModel::RowViewModel(Group *group) :
    _login(group->getName()), _checkBox(false)
{

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
