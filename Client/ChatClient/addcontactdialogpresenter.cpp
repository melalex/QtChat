#include "addcontactdialogpresenter.h"
#include "addcontactdialog.h"

AddContactDialogPresenter::AddContactDialogPresenter(QObject *parent) : QObject(parent)
{
    _addContactDialog = new AddContactDialog();
}

AddContactDialogPresenter::~AddContactDialogPresenter()
{
    delete _addContactDialog;
}

void AddContactDialogPresenter::showWindow()
{
    _addContactDialog->show();
}
