#include "authorizationpresenter.h"
#include "authorization.h"
#include "connectionmenager.h"
#include "registrationpresenter.h"
#include "contactspresenter.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QApplication>

AuthorizationPresenter::AuthorizationPresenter(QObject *parent) :
    QObject(parent)
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
    connect(_connectionMenager, SIGNAL(connectionFail(QString)), this, SLOT(showHostSelectDialog(QString)));

    showHostSelectDialog("Set host name");
}

void AuthorizationPresenter::showHostSelectDialog(QString header)
{
    _authorization->lockUI();

    bool ok;
    QString name = QInputDialog::getText(_authorization, QString(header),
                                                         QString("Host name:"),
                                                         QLineEdit::Normal,
                                                         QString("127.0.0.1"),
                                                         &ok);
    if (ok && !name.isEmpty())
    {
        _connectionMenager->connectToHost(name);
        _authorization->unLockUI();
    }
    else
    {
        _authorization->close();
        qApp->quit();
        qApp->exit();
    }
}

RegistrationPresenter *AuthorizationPresenter::getRegistrationWindow()
{
    if (!_registrationWindow)
    {
        _registrationWindow = new RegistrationPresenter();
        _registrationWindow->setConnectionMenager(_connectionMenager);
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

    disconnect(_connectionMenager, SIGNAL(connectionFail(QString)), this, SLOT(showHostSelectDialog(QString)));
}

void AuthorizationPresenter::notLogged()
{
    _authorization->clearInput();
    _authorization->unLockUI();

    QMessageBox msgBox;
    msgBox.setText("Incorrect login or password");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();
}
