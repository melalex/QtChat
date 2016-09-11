#include "registration.h"
#include "ui_registration.h"

#include <QLineEdit>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::lockUI()
{
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->pushButton->setEnabled(false);
}

void Registration::unLockUI()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->pushButton->setEnabled(true);
}


void Registration::on_pushButton_clicked()
{
    lockUI();
    registerANewUser(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text());
}

void Registration::clearInput()
{
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
