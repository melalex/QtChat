#ifndef GROUPCHATDIALOGPRESENTER_H
#define GROUPCHATDIALOGPRESENTER_H

#include <QObject>

class GroupChatDialogPresenter : public QObject
{
    Q_OBJECT
public:
    explicit GroupChatDialogPresenter(QObject *parent = 0);

signals:

public slots:
};

#endif // GROUPCHATDIALOGPRESENTER_H