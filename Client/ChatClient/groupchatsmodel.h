#ifndef GROUPCHATSMODEL_H
#define GROUPCHATSMODEL_H

#include <QAbstractTableModel>

class Model;
class Group;

class GroupChatsModel: public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit GroupChatsModel(Model *model, QObject *parent = 0);
    ~GroupChatsModel();

    void clear();

private:
    Model *_model;
    QStringList _tableModel;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

private slots:
    void groupChatAdded(Group *chat);
    void groupChatRemoved(quint16 index);

};

#endif // GROUPCHATSMODEL_H
