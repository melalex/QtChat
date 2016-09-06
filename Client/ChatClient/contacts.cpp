#include "contacts.h"
#include "ui_contacts.h"
#include "addcontactdialog.h"

Contacts::Contacts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Contacts)
{
    ui->setupUi(this);
}

Contacts::~Contacts()
{
    delete ui;
}


AddContactDialog *Contacts::getAddContactDialog()
{
    if (!_addContactDialog)
    {
        _addContactDialog = new AddContactDialog(this);
    }
    return _addContactDialog;
}

void Contacts::on_pushButton_17_clicked()
{
    getAddContactDialog()->show();
}
