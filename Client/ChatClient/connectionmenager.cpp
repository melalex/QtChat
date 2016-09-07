#include "connectionmenager.h"
#include "model.h"

ConnectionMenager::ConnectionMenager(QObject *parent) :
    QObject(parent),
    _model(new Model(this))
{

}

ConnectionMenager::~ConnectionMenager()
{

}

Model *ConnectionMenager::model()
{
    return _model;
}
