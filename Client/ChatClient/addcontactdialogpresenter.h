#ifndef ADDCONTACTDIALOGPRESENTER_H
#define ADDCONTACTDIALOGPRESENTER_H

#include <QObject>

class AddContactDialog;
class ConnectionMenager;
class Model;
class User;

class AddContactDialogPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AddContactDialogPresenter(Model *model, ConnectionMenager *connectionMenager, QObject *parent = 0);
    ~AddContactDialogPresenter();

    void showWindow();

signals:
    void setPossibleContacts(const QList<User *> *users);

public slots:
    void getPossibleContacts(QString loginPart);
    void addContact(quint16 index);

    void possibleContacts(QList<User *> *users);

private:
    AddContactDialog *_addContactDialog;
    ConnectionMenager *_connectionMenager;
    Model *_model;

    QList<User *> *_possibleContacts = nullptr;
};

#endif // ADDCONTACTDIALOGPRESENTER_H
