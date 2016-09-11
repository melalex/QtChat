#include <QCoreApplication>
#include "chatserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ChatServer server;

    server.startServer(QHostAddress::LocalHost, 8000);

    return a.exec();
}
