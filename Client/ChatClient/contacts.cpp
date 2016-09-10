#include "contacts.h"
#include "ui_contacts.h"
#include "addcontactdialog.h"
#include "chatsmodel.h"
#include "groupchatsmodel.h"
#include "chatdialogpresenter.h"
#include "groupchatdialogpresenter.h"

#include <QDebug>

Contacts::Contacts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Contacts)
{
    ui->setupUi(this);

    ui->pushButton_18->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_23->setEnabled(false);

    ui->tableView_5->verticalHeader()->hide();
    ui->tableView_5->horizontalHeader()->hide();
    ui->tableView_5->setShowGrid(false);
    ui->tableView_5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_5->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView_6->verticalHeader()->hide();
    ui->tableView_6->horizontalHeader()->hide();
    ui->tableView_6->setShowGrid(false);
    ui->tableView_6->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_6->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Contacts::~Contacts()
{
    delete ui;
}

void Contacts::setTableModel(ChatsModel *chatsModel, GroupChatsModel *groupChatsModel)
{
    ui->tableView_5->setModel(chatsModel);
    ui->tableView_6->setModel(groupChatsModel);

    connect(
      ui->tableView_5->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),
      this,
      SLOT(chatSelectionChanged())
    );

    connect(
      ui->tableView_6->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),
      this,
      SLOT(groupChatSelectionChanged(const QItemSelection &))
    );

    ui->tableView_5->setColumnHidden(1, true);
}

void Contacts::setMyLogin(QString login)
{
    ui->label->setText(login);
}

void Contacts::tryEnablePushButton18()
{
    QItemSelection selected = ui->tableView_5->selectionModel()->selection();

    if (selected.indexes().isEmpty())
    {
        ui->pushButton_18->setEnabled(false);
    }
    else
    {
        ui->pushButton_18->setEnabled(true);
    }
}

void Contacts::chatSelectionChanged()
{
    tryEnablePushButton18();
}

void Contacts::groupChatSelectionChanged(const QItemSelection &selection)
{
    if (selection.indexes().isEmpty())
    {
        ui->pushButton_23->setEnabled(false);
    }
    else
    {
        ui->pushButton_23->setEnabled(true);
    }
}

void Contacts::on_pushButton_17_clicked()
{
    addContact();
}

void Contacts::on_pushButton_18_clicked()
{
    QItemSelection selected = ui->tableView_5->selectionModel()->selection();

    emit removeContact(selected.indexes().at(0).row());
}

void Contacts::on_pushButton_19_clicked()
{
    ui->tableView_5->setColumnHidden(1, false);

    ui->pushButton_18->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(true);
}

void Contacts::on_pushButton_20_clicked()
{
    ui->tableView_5->setColumnHidden(1, true);

    tryEnablePushButton18();
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_20->setEnabled(false);

    QList<quint16> *selectedItems = static_cast<ChatsModel *>(ui->tableView_5->model())->selectedItems();

    if (selectedItems->count() > 2)
    {
        emit createGroup(selectedItems);
    }

    delete selectedItems;
}

void Contacts::on_pushButton_23_clicked()
{
    QItemSelection selected = ui->tableView_6->selectionModel()->selection();

    emit leaveGroup(selected.indexes().at(0).row());
}

void Contacts::on_tableView_5_doubleClicked(const QModelIndex &index)
{
    emit openChat(index.row());
}

void Contacts::on_tableView_6_doubleClicked(const QModelIndex &index)
{
    emit openGroupChat(index.row());
}
