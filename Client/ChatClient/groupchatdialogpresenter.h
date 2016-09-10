#ifndef GROUPCHATDIALOGPRESENTER_H
#define GROUPCHATDIALOGPRESENTER_H

#include <QObject>

class Group;
class User;
class Message;
class GroupChatDialog;

class GroupChatDialogPresenter : public QObject
{
    Q_OBJECT
public:
    explicit GroupChatDialogPresenter(QObject *parent = 0);
    ~GroupChatDialogPresenter();

    void setGroup(Group *group);
    Group *group();

    void showWindow();
    void hideWindow();

signals:
    void setMembers(const QList<User *> *members);

public slots:
    void messageAdded(Message *message);
    void messageAdded(QString message);

private:
    GroupChatDialog *_chat;
    Group *_group = nullptr;
};

#endif // GROUPCHATDIALOGPRESENTER_H
