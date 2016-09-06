#ifndef CONTACTS_H
#define CONTACTS_H

#include <QMainWindow>

class AddContactDialog;

namespace Ui {
class Contacts;
}

class Contacts : public QMainWindow
{
    Q_OBJECT

public:
    explicit Contacts(QWidget *parent = 0);
    ~Contacts();



private slots:
    void on_pushButton_17_clicked();

private:
    Ui::Contacts *ui;
    AddContactDialog *_addContactDialog = nullptr;

    AddContactDialog *getAddContactDialog();
};

#endif // CONTACTS_H
