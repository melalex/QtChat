/********************************************************************************
** Form generated from reading UI file 'groupchatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATDIALOG_H
#define UI_GROUPCHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_GroupChatDialog
{
public:
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QPlainTextEdit *plainTextEdit_2;
    QTableView *tableView;

    void setupUi(QDialog *GroupChatDialog)
    {
        if (GroupChatDialog->objectName().isEmpty())
            GroupChatDialog->setObjectName(QStringLiteral("GroupChatDialog"));
        GroupChatDialog->resize(602, 284);
        pushButton = new QPushButton(GroupChatDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 230, 71, 41));
        plainTextEdit = new QPlainTextEdit(GroupChatDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 30, 371, 191));
        plainTextEdit->setUndoRedoEnabled(false);
        plainTextEdit->setReadOnly(true);
        label = new QLabel(GroupChatDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 371, 16));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        plainTextEdit_2 = new QPlainTextEdit(GroupChatDialog);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(10, 230, 291, 41));
        tableView = new QTableView(GroupChatDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(390, 30, 201, 241));

        retranslateUi(GroupChatDialog);

        QMetaObject::connectSlotsByName(GroupChatDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupChatDialog)
    {
        GroupChatDialog->setWindowTitle(QApplication::translate("GroupChatDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("GroupChatDialog", "Send", 0));
        label->setText(QApplication::translate("GroupChatDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupChatDialog: public Ui_GroupChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATDIALOG_H
