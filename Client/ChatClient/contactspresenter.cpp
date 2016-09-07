#include "contactspresenter.h"
#include "addcontactdialogpresenter.h"
#include "contacts.h"

ContactsPresenter::ContactsPresenter(QObject *parent) : QObject(parent)
{
    _contacts = new Contacts();
    connect(_contacts, SIGNAL(addContact()), this, SLOT(addContact()));
}

ContactsPresenter::~ContactsPresenter()
{
    delete _contacts;
}

void ContactsPresenter::showWindow()
{
    _contacts->show();
}

AddContactDialogPresenter *ContactsPresenter::getAddContactDialog()
{
    if (!_addContactDialog)
    {
        _addContactDialog = new AddContactDialogPresenter(this);
    }
    return _addContactDialog;
}

void ContactsPresenter::addContact()
{
    getAddContactDialog()->showWindow();
}
