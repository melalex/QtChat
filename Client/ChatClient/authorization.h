#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = 0);
    ~Authorization();

    void clearInput();

    void lockUI();
    void unLockUI();

signals:
    void signUp();
    void signIn(QString login, QString password);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
