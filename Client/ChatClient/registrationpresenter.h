#ifndef REGISTRATIONPRESENTER_H
#define REGISTRATIONPRESENTER_H

#include <QObject>

class Registration;
class ConnectionMenager;

class RegistrationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationPresenter(QObject *parent = 0);
    ~RegistrationPresenter();

    void showWindow();

    void setConnectionMenager(ConnectionMenager *connectionMenager);

signals:

public slots:
    void registerANewUser(QString login, QString password, QString confirmPassword);

    void registered();
    void notRegistered();

private:
    Registration *_registration;
    ConnectionMenager *_connectionMenager;
};

#endif // REGISTRATIONPRESENTER_H
