#include "authorizationpresenter.h"
#include "authorization.h"
#include "connectionmenager.h"
#include "registrationpresenter.h"
#include "contactspresenter.h"

#include <QMessageBox>

AuthorizationPresenter::AuthorizationPresenter(QObject *parent) : QObject(parent)
{
    _authorization = new Authorization();
    connect(_authorization, SIGNAL(signIn(QString,QString)), this, SLOT(signIn(QString,QString)));
    connect(_authorization, SIGNAL(signUp()), this, SLOT(signUp()));
}

AuthorizationPresenter::~AuthorizationPresenter()
{
    if (_registrationWindow)
    {
        delete _registrationWindow;
    }
    delete _authorization;
}

void AuthorizationPresenter::showWindow()
{
    _authorization->show();
}

void AuthorizationPresenter::setContacts(ContactsPresenter *contacts)
{
    _contacts = contacts;
}

void AuthorizationPresenter::setConnectionMenager(ConnectionMenager *connectionMenager)
{
    _connectionMenager = connectionMenager;

    connect(_connectionMenager, SIGNAL(logged()), this, SLOT(logged()));
    connect(_connectionMenager, SIGNAL(notLogged()), this, SLOT(notLogged()));
}

RegistrationPresenter *AuthorizationPresenter::getRegistrationWindow()
{
    if (!_registrationWindow)
    {
        _registrationWindow = new RegistrationPresenter();
    }
    return _registrationWindow;
}

void AuthorizationPresenter::signUp()
{
    getRegistrationWindow()->showWindow();
}

void AuthorizationPresenter::signIn(QString login, QString password)
{
    if(!login.isEmpty() &&
       login.count() > 2 &&
       login.count() < 21 &&
       !password.isEmpty() &&
       password.count() > 2 &&
       password.count() < 21)
    {
        _connectionMenager->signIn(login, password);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Fields must be longer than two or shorter than twenty characters");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void AuthorizationPresenter::logged()
{
    _contacts->setConnectionMenager(_connectionMenager);
    _contacts->showWindow();
    _authorization->close();
}

void AuthorizationPresenter::notLogged()
{
    _authorization->clearInput();

    QMessageBox msgBox;
    msgBox.setText("Incorrect login or password");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();
}
