#ifndef CONTACTSPRESENTER_H
#define CONTACTSPRESENTER_H

#include <QObject>

class AddContactDialogPresenter;
class Contacts;

class ContactsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ContactsPresenter(QObject *parent = 0);
    ~ContactsPresenter();

    void showWindow();

signals:

public slots:
    void addContact();

private:
    Contacts *_contacts;
    AddContactDialogPresenter *_addContactDialog = nullptr;

    AddContactDialogPresenter *getAddContactDialog();
};

#endif // CONTACTSPRESENTER_H
