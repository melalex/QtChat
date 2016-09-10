#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = 0);
    ~ChatDialog();

    void setInterlocutor(QString login);

    void printMessage(QString message);
    void clearOutput();

signals:
    void messageAdded(QString message);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChatDialog *ui;
};

#endif // CHATDIALOG_H
