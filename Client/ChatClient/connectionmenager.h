#ifndef CONNECTIONMENAGER_H
#define CONNECTIONMENAGER_H

#include <QObject>

class Model;

class ConnectionMenager : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionMenager(QObject *parent = 0);
    ~ConnectionMenager();

    Model *model();

private:
    Model *_model;
};

#endif // CONNECTIONMENAGER_H
