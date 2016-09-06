#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

class Registration;
class Contacts;

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = 0);
    ~Authorization();

    void setContactsWindow(Contacts *contacts);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Authorization *ui;
    Registration *_registrationWindow = nullptr;
    Contacts *_contacts;

    Registration *getRegistrationWindow();
};

#endif // AUTHORIZATION_H
