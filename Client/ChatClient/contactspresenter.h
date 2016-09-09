#ifndef CONTACTSPRESENTER_H
#define CONTACTSPRESENTER_H

#include <QObject>

class AddContactDialogPresenter;
class Contacts;
class ConnectionMenager;
class Model;

class ContactsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ContactsPresenter(QObject *parent = 0);
    ~ContactsPresenter();

    void showWindow();

    void setConnectionMenager(ConnectionMenager *connectionMenager);

signals:

public slots:
    void addContact();
    void createGroup(QList<quint16> *indexes);

private:
    Contacts *_contacts;
    ConnectionMenager *_connectionMenager;
    Model *_model;
    AddContactDialogPresenter *_addContactDialog = nullptr;

    AddContactDialogPresenter *getAddContactDialog();
};

#endif // CONTACTSPRESENTER_H
