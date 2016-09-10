#ifndef POSSIBLECONTACTSMODEL_H
#define POSSIBLECONTACTSMODEL_H

#include <QAbstractTableModel>

class User;

class PossibleContactsModel: public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PossibleContactsModel(QObject *parent = 0);
    ~PossibleContactsModel();

    void clear();

private:
    QStringList _tableModel;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

private slots:
    void setPossibleContacts(QList<User *> *users);

};

#endif // POSSIBLECONTACTSMODEL_H
