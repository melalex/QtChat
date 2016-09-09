#ifndef CONTACTS_H
#define CONTACTS_H

#include <QMainWindow>
#include <QTableView>

class AddContactDialog;
class ChatsModel;
class GroupChatsModel;

namespace Ui {
class Contacts;
}

class Contacts : public QMainWindow
{
    Q_OBJECT

public:
    explicit Contacts(QWidget *parent = 0);
    ~Contacts();

    void setTableModel(ChatsModel *chatsModel, GroupChatsModel *groupChatsModel);
    void setMyLogin(QString login);

signals:
    void addContact();
    void createGroup(QList<quint16> *indexes);

private slots:
    void chatSelectionChanged();
    void groupChatSelectionChanged(const QItemSelection &selection);

    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

private:
    Ui::Contacts *ui;

    void tryEnablePushButton18();
};

#endif // CONTACTS_H
