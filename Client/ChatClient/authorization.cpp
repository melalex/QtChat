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

void Authorization::on_pushButton_clicked()
{
    signIn(ui->lineEdit->text(), ui->label_2->text());
}

void Authorization::on_pushButton_2_clicked()
{
    signUp();
}
