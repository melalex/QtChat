#include "authorizationpresenter.h"
#include "authorization.h"
#include "connectionmenager.h"
#include "registrationpresenter.h"
#include "contactspresenter.h"

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
    _contacts->showWindow();
    _authorization->close();
}
