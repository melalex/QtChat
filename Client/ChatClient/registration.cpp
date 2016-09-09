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

void Registration::on_pushButton_clicked()
{
    registerANewUser(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text());
}

void Registration::clearInput()
{
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
