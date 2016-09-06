#ifndef AUTHORIZATIONPRESENTER_H
#define AUTHORIZATIONPRESENTER_H

#include <QObject>

class AuthorizationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationPresenter(QObject *parent = 0);

signals:

public slots:
};

#endif // AUTHORIZATIONPRESENTER_H