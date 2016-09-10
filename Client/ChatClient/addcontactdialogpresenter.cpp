#include "addcontactdialogpresenter.h"
#include "addcontactdialog.h"
#include "connectionmenager.h"
#include "model.h"
#include "group.h"
#include "user.h"
#include "possiblecontactsmodel.h"

#include <QMessageBox>

AddContactDialogPresenter::AddContactDialogPresenter(Model *model, ConnectionMenager *connectionMenager, QObject *parent) :
    QObject(parent), _model(model), _connectionMenager(connectionMenager)
{
    _addContactDialog = new AddContactDialog();

    PossibleContactsModel *possibleContactsModel = new PossibleContactsModel(this);

    connect(this, SIGNAL(setPossibleContacts(const QList<User*>*)), possibleContactsModel, SLOT(setPossibleContacts(const QList<User*>*)));

    _addContactDialog->setTableModel(possibleContactsModel);

    connect(_addContactDialog, SIGNAL(getPossibleContacts(QString)), this, SLOT(getPossibleContacts(QString)));
    connect(_addContactDialog, SIGNAL(addContact(quint16)), this, SLOT(addContact(quint16)));

    connect(_connectionMenager, SIGNAL(possibleContacts(QList<User*>*)), this, SLOT(possibleContacts(QList<User*>*)));
}

AddContactDialogPresenter::~AddContactDialogPresenter()
{
    if (_possibleContacts != nullptr)
    {
        qDeleteAll(*_possibleContacts);
        delete _possibleContacts;
    }

    delete _addContactDialog;
}

void AddContactDialogPresenter::showWindow()
{
    _addContactDialog->show();
}

void AddContactDialogPresenter::getPossibleContacts(QString loginPart)
{
    if (!loginPart.isEmpty() && loginPart.count() > 2)
    {
        _connectionMenager->getPossibleContacts(loginPart);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Search string must be longer than two characters");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void AddContactDialogPresenter::addContact(quint16 index)
{
    User *user = _possibleContacts->at(index);

    _model->createChat(user);

    _addContactDialog->hideWindow();
}

void AddContactDialogPresenter::possibleContacts(QList<User *> *users)
{
    if (_possibleContacts != users)
    {
        if (_possibleContacts != nullptr)
        {
            qDeleteAll(*_possibleContacts);
        }

        _possibleContacts = users;

        emit setPossibleContacts(users);
    }
}
