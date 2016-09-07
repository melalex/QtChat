#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QList>

class Group;
class User;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    ~Model();

    void addChat(Group *chat);
    void addGroupChat(Group *chat);

    void removeChat(Group *chat);
    void removeGroupChat(Group *chat);

    User *currentUser();
    void setCurrentUser(User *user);

signals:
    void chatAdded(Group *chat);
    void groupChatAdded(Group *chat);

    void chatRemoved();
    void groupChatRemoved();

public slots:

private:
    QList<Group *> _chats;
    QList<Group *> _groupChats;

    User *_currentUser;
};

#endif // MODEL_H
