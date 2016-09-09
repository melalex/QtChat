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

private:
    Model *_model;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
};

#endif // GROUPCHATSMODEL_H
