#include "connectionmenager.h"
#include "user.h"
#include "group.h"
#include "message.h"

ConnectionMenager::ConnectionMenager(QObject *parent) :
    QObject(parent)
{

}

ConnectionMenager::~ConnectionMenager()
{
    delete _currentUser;
}

User *ConnectionMenager::currentUser()
{
    return _currentUser;
}

void ConnectionMenager::signUp(QString login, QString password)
{
    registered();
}

void ConnectionMenager::signIn(QString login, QString password)
{
    _currentUser = new User(0, "Me");
    logged();
}

void ConnectionMenager::addContact(User *user)
{

}

void ConnectionMenager::createGroupChat(QList<User *> users, QString name)
{

}

void ConnectionMenager::sendMessage(Message *message)
{

}

QList<Group *> *ConnectionMenager::getChats()
{
    QList<Group *> *result = new QList<Group *>();

    User *user1 = new User(1, "User1");
    User *user2 = new User(2, "User2");
    User *user3 = new User(3, "User3");
    User *user4 = new User(4, "User4");

    QList<User *> *list1 = new QList<User *>();
    list1->append(user1);

    QList<User *> *list2 = new QList<User *>();
    list2->append(user2);

    QList<User *> *list3 = new QList<User *>();
    list3->append(user3);

    QList<User *> *list4 = new QList<User *>();
    list4->append(user4);

    Group *group1 = new Group(0, user1->getLogin(), list1);
    Group *group2 = new Group(1, user2->getLogin(), list2);
    Group *group3 = new Group(2, user3->getLogin(), list3);
    Group *group4 = new Group(3, user4->getLogin(), list4);

    result->append(group1);
    result->append(group2);
    result->append(group3);
    result->append(group4);

    return result;
}

QList<Group *> *ConnectionMenager::getGroupChats()
{
    QList<Group *> *result = new QList<Group *>();

    User *user5 = new User(5, "User1");
    User *user6 = new User(6, "User2");
    User *user7 = new User(7, "User3");

    QList<User *> *list5 = new QList<User *>();
    list5->append(user5);
    list5->append(user6);
    list5->append(user7);

    Group *group5 = new Group(4, "Group 5", list5);

    result->append(group5);

    return result;
}

QList<User *> *ConnectionMenager::getPossibleContacts(QString loginPart)
{
    QList<User *> *result = new QList<User *>();
    return result;
}
