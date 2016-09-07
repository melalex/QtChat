#ifndef ADDCONTACTDIALOGPRESENTER_H
#define ADDCONTACTDIALOGPRESENTER_H

#include <QObject>

class AddContactDialog;

class AddContactDialogPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AddContactDialogPresenter(QObject *parent = 0);
    ~AddContactDialogPresenter();

    void showWindow();

signals:

public slots:

private:
    AddContactDialog *_addContactDialog;
};

#endif // ADDCONTACTDIALOGPRESENTER_H
