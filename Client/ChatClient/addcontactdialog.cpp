#include "addcontactdialog.h"
#include "ui_addcontactdialog.h"
#include "possiblecontactsmodel.h"

AddContactDialog::AddContactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContactDialog)
{
    ui->setupUi(this);

    ui->pushButton->setEnabled(false);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->hide();
    ui->tableView->setShowGrid(false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

AddContactDialog::~AddContactDialog()
{
    delete ui;
}

void AddContactDialog::hideWindow()
{
    ui->lineEdit->setText("");

    static_cast<PossibleContactsModel *>(ui->tableView->model())->clear();

    close();
}

void AddContactDialog::setTableModel(QAbstractTableModel *tableModel)
{
    ui->tableView->setModel(tableModel);

    connect(
      ui->tableView->selectionModel(),
      SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),
      this,
      SLOT(selectionChanged(const QItemSelection &))
    );
}

void AddContactDialog::selectionChanged(const QItemSelection &selection)
{
    if (selection.indexes().isEmpty())
    {
        ui->pushButton->setEnabled(false);
    }
    else
    {
        ui->pushButton->setEnabled(true);
    }
}

void AddContactDialog::on_pushButton_clicked()
{
    QItemSelection selected = ui->tableView->selectionModel()->selection();

    emit addContact(selected.indexes().at(0).row());
}

void AddContactDialog::on_pushButton_2_clicked()
{
    emit getPossibleContacts(ui->lineEdit->text());
}

