#ifndef CHATDIALOGPRESENTER_H
#define CHATDIALOGPRESENTER_H

#include <QObject>

class ChatDialogPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ChatDialogPresenter(QObject *parent = 0);

signals:

public slots:
};

#endif // CHATDIALOGPRESENTER_H