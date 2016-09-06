/********************************************************************************
** Form generated from reading UI file 'addcontactdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACTDIALOG_H
#define UI_ADDCONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddContactDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *AddContactDialog)
    {
        if (AddContactDialog->objectName().isEmpty())
            AddContactDialog->setObjectName(QStringLiteral("AddContactDialog"));
        AddContactDialog->resize(282, 271);
        widget = new QWidget(AddContactDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 258, 249));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/w256h2561380453921Search256x25632.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/person_add-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        verticalLayout->addWidget(pushButton);


        retranslateUi(AddContactDialog);

        QMetaObject::connectSlotsByName(AddContactDialog);
    } // setupUi

    void retranslateUi(QDialog *AddContactDialog)
    {
        AddContactDialog->setWindowTitle(QApplication::translate("AddContactDialog", "Dialog", 0));
        pushButton_2->setText(QString());
        pushButton->setText(QApplication::translate("AddContactDialog", "Add to contacts", 0));
    } // retranslateUi

};

namespace Ui {
    class AddContactDialog: public Ui_AddContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTDIALOG_H
