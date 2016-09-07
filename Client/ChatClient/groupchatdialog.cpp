#include "groupchatdialog.h"
#include "ui_groupchatdialog.h"

GroupChatDialog::GroupChatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupChatDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

GroupChatDialog::~GroupChatDialog()
{
    delete ui;
}
