#include "registrationpresenter.h"
#include "registration.h"
#include "connectionmenager.h"

#include <QMessageBox>

RegistrationPresenter::RegistrationPresenter(QObject *parent) : QObject(parent)
{
    _registration = new Registration();

    connect(_registration, SIGNAL(registerANewUser(QString,QString,QString)), this, SLOT(registerANewUser(QString,QString,QString)));
}

RegistrationPresenter::~RegistrationPresenter()
{
    delete _registration;
}

void RegistrationPresenter::showWindow()
{
    _registration->show();
}

void RegistrationPresenter::setConnectionMenager(ConnectionMenager *connectionMenager)
{
    _connectionMenager = connectionMenager;

    connect(_connectionMenager, SIGNAL(registered()), this, SLOT(registered()));
    connect(_connectionMenager, SIGNAL(notRegistered()), this, SLOT(notRegistered()));
}

void RegistrationPresenter::registerANewUser(QString login, QString password, QString confirmPassword)
{
    if (!login.isEmpty() &&
        login.count() > 2 &&
        login.count() < 21 &&
        !password.isEmpty() &&
        password.count() > 2 &&
        password.count() < 21 &&
        QString::compare(password, confirmPassword, Qt::CaseSensitive) == 0)
    {
        _connectionMenager->signUp(login, password);
    }
    else
    {
        _registration->clearInput();
        _registration->unLockUI();

        QMessageBox msgBox;
        msgBox.setText("Incorrect input");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void RegistrationPresenter::registered()
{
    _registration->unLockUI();
    _registration->close();
}

void RegistrationPresenter::notRegistered()
{
    _registration->unLockUI();
    _registration->clearInput();

    QMessageBox msgBox;
    msgBox.setText("A user with this login already exists");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.exec();
}
