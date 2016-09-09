#ifndef CHATSMODEL_H
#define CHATSMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QString>

class Model;
class Group;

class RowViewModel
{
public:
    RowViewModel(Group *group);

    QString login();

    bool isChecked();
    void check();
    void unCheck();

private:
    QString _login;
    bool _checkBox;
};

class ChatsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ChatsModel(Model *model, QObject *parent = 0);
    ~ChatsModel();

    QList<quint16> *selectedItems();

private:
    Model *_model;
    QList<RowViewModel *> _tableModel;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
};

#endif // CHATSMODEL_H
