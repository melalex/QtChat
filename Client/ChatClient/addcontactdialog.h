#ifndef ADDCONTACTDIALOG_H
#define ADDCONTACTDIALOG_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class AddContactDialog;
}

class AddContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddContactDialog(QWidget *parent = 0);
    ~AddContactDialog();

    void hideWindow();

    void setTableModel(QAbstractTableModel *tableModel);

signals:
    void getPossibleContacts(QString loginPart);
    void addContact(quint16);

private slots:
    void selectionChanged(const QItemSelection &selection);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::AddContactDialog *ui;
};

#endif // ADDCONTACTDIALOG_H
