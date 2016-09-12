#ifndef AUTHORIZATIONPRESENTER_H
#define AUTHORIZATIONPRESENTER_H

#include <QObject>

class RegistrationPresenter;
class ContactsPresenter;
class ConnectionMenager;
class Authorization;

class AuthorizationPresenter : public QObject
{
    Q_OBJECT

public:
    explicit AuthorizationPresenter(QObject *parent = 0);
    ~AuthorizationPresenter();

    void showWindow();

    void setContacts(ContactsPresenter *contacts);
    void setConnectionMenager(ConnectionMenager *connectionMenager);

signals:

public slots:
    void signUp();
    void signIn(QString login, QString password);

    void logged();
    void notLogged();

    void showHostSelectDialog(QString header);

private:
    Authorization *_authorization;
    ConnectionMenager *_connectionMenager;
    RegistrationPresenter *_registrationWindow = nullptr;
    ContactsPresenter *_contacts;

    RegistrationPresenter *getRegistrationWindow();

};

#endif // AUTHORIZATIONPRESENTER_H
