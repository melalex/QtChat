#ifndef GROUPCHATDIALOG_H
#define GROUPCHATDIALOG_H

#include <QDialog>

class QAbstractTableModel;

namespace Ui {
class GroupChatDialog;
}

class GroupChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupChatDialog(QWidget *parent = 0);
    ~GroupChatDialog();

    void setInterlocutor(QString groupName);
    void setTableModel(QAbstractTableModel *tableModel);

    void printMessage(QString message);
    void clearOutput();

    void removeMember(quint16 index);

signals:
    void messageAdded(QString message);

private slots:

    void on_pushButton_clicked();

private:
    Ui::GroupChatDialog *ui;
};

#endif // GROUPCHATDIALOG_H
