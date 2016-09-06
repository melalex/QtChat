#include "authorization.h"
#include "ui_authorization.h"
#include "registration.h"
#include "contacts.h"

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete _registrationWindow;

    delete ui;
}

void Authorization::setContactsWindow(Contacts *contacts)
{
    _contacts = contacts;
}

Registration *Authorization::getRegistrationWindow()
{
    if (!_registrationWindow)
    {
        _registrationWindow = new Registration();
    }
    return _registrationWindow;
}

void Authorization::on_pushButton_clicked()
{
    _contacts->show();
    this->close();
}

void Authorization::on_pushButton_2_clicked()
{
    getRegistrationWindow()->show();
}
