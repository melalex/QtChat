#include "authorizationpresenter.h"
#include "contactspresenter.h"
#include "connectionmenager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AuthorizationPresenter authorizationPresenter;
    authorizationPresenter.showWindow();

    ContactsPresenter contacts;
    ConnectionMenager connectionMenager;

    authorizationPresenter.setContacts(&contacts);
    authorizationPresenter.setConnectionMenager(&connectionMenager);

    return a.exec();
}
