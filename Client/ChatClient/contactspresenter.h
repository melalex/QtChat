#ifndef CONTACTSPRESENTER_H
#define CONTACTSPRESENTER_H

#include <QObject>

class ContactsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ContactsPresenter(QObject *parent = 0);

signals:

public slots:
};

#endif // CONTACTSPRESENTER_H