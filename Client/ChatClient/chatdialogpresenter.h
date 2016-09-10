#ifndef CHATDIALOGPRESENTER_H
#define CHATDIALOGPRESENTER_H

#include <QObject>

class Group;
class Message;
class ChatDialog;

class ChatDialogPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ChatDialogPresenter(QObject *parent = 0);
    ~ChatDialogPresenter();

    void setGroup(Group *group);

    void showWindow();

public slots:
    void messageAdded(Message *message);
    void messageAdded(QString message);

private:
    ChatDialog *_chat;
    Group *_group = nullptr;
};

#endif // CHATDIALOGPRESENTER_H
