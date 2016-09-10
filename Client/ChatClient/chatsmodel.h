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
    RowViewModel();
    RowViewModel(QString login);
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

    QList<quint16> *selectedItems() const;

private:
    Model *_model;
    QList<RowViewModel *> _tableModel;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

private slots:
    void chatAdded(Group *chat);
    void chatRemoved(quint16 index);
    
};

#endif // CHATSMODEL_H
