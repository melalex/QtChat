#include "chatdialog.h"
#include "ui_chatdialog.h"

ChatDialog::ChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

void ChatDialog::setInterlocutor(QString login)
{
    ui->label->setText(login);
}

void ChatDialog::printMessage(QString message)
{
    ui->plainTextEdit->insertPlainText(message);
}

void ChatDialog::clearOutput()
{
    ui->plainTextEdit->clear();
}

void ChatDialog::on_pushButton_clicked()
{
    emit messageAdded(ui->plainTextEdit_2->toPlainText());
    ui->plainTextEdit_2->clear();
}
