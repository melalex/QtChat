#include "authorization.h"
#include "contacts.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Authorization w;
    w.show();

    Contacts contacts;

    w.setContactsWindow(&contacts);

    return a.exec();
}
