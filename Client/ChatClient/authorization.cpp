#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::clearInput()
{
    ui->lineEdit_2->clear();
}

void Authorization::lockUI()
{
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

void Authorization::unLockUI()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void Authorization::on_pushButton_clicked()
{
    lockUI();
    signIn(ui->lineEdit->text(), ui->lineEdit_2->text());
}

void Authorization::on_pushButton_2_clicked()
{
    signUp();
}
