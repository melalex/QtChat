#include "registrationpresenter.h"
#include "registration.h"

RegistrationPresenter::RegistrationPresenter(QObject *parent) : QObject(parent)
{
    _registration = new Registration();
}

RegistrationPresenter::~RegistrationPresenter()
{
    delete _registration;
}

void RegistrationPresenter::showWindow()
{
    _registration->show();
}

void RegistrationPresenter::registerANewUser(QString login, QString password, QString confirmPassword)
{

}
