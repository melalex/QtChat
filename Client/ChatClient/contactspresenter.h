#ifndef CONTACTSPRESENTER_H
#define CONTACTSPRESENTER_H

#include <QObject>

class AddContactDialogPresenter;
class Contacts;
class ConnectionMenager;
class Model;
class GroupChatDialogPresenter;
class ChatDialogPresenter;

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
    void connectionFail(QString socketError);

    void addContact();
    void removeContact(quint16 index);

    void createGroup(QList<quint16> *indexes);
    void leaveGroup(quint16 index);

    void openChat(quint16 index);
    void openGroupChat(quint16 index);

private:
    Contacts *_contacts;
    ConnectionMenager *_connectionMenager;
    Model *_model;
    AddContactDialogPresenter *_addContactDialog = nullptr;
    GroupChatDialogPresenter *_groupChatDialogPresenter = nullptr;
    ChatDialogPresenter *_chatDialogPresenter = nullptr;

    AddContactDialogPresenter *getAddContactDialog();
    GroupChatDialogPresenter *getGroupChatDialogPresenter();
    ChatDialogPresenter *getChatDialogPresenter();
};

#endif // CONTACTSPRESENTER_H
