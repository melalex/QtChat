#ifndef GROUPCHATDIALOG_H
#define GROUPCHATDIALOG_H

#include <QDialog>

namespace Ui {
class GroupChatDialog;
}

class GroupChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupChatDialog(QWidget *parent = 0);
    ~GroupChatDialog();

private:
    Ui::GroupChatDialog *ui;
};

#endif // GROUPCHATDIALOG_H
