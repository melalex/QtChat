#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>

namespace Ui {
class Authorization;
}

class Authorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = 0);
    ~Authorization();

private:
    Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
