#ifndef REGISTRATIONPRESENTER_H
#define REGISTRATIONPRESENTER_H

#include <QObject>

class Registration;

class RegistrationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationPresenter(QObject *parent = 0);
    ~RegistrationPresenter();

    void showWindow();

signals:

public slots:
    void registerANewUser(QString login, QString password, QString confirmPassword);

private:
    Registration *_registration;

};

#endif // REGISTRATIONPRESENTER_H
