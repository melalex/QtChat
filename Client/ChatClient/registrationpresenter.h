#ifndef REGISTRATIONPRESENTER_H
#define REGISTRATIONPRESENTER_H

#include <QObject>

class RegistrationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationPresenter(QObject *parent = 0);

signals:

public slots:
};

#endif // REGISTRATIONPRESENTER_H