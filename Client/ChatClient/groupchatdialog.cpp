#include "groupchatdialog.h"
#include "ui_groupchatdialog.h"

GroupChatDialog::GroupChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupChatDialog)
{
    ui->setupUi(this);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->hide();
    ui->tableView->setShowGrid(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

GroupChatDialog::~GroupChatDialog()
{
    delete ui;
}

void GroupChatDialog::setInterlocutor(QString groupName)
{
    ui->label->setText(groupName);
}

void GroupChatDialog::setTableModel(QAbstractTableModel *tableModel)
{
    ui->tableView->setModel(tableModel);
}

void GroupChatDialog::printMessage(QString message)
{
    ui->plainTextEdit->insertPlainText(message);
}

void GroupChatDialog::clearOutput()
{
    ui->plainTextEdit->clear();
}

void GroupChatDialog::on_pushButton_clicked()
{
    emit messageAdded(ui->plainTextEdit_2->toPlainText());
    ui->plainTextEdit_2->clear();
}
