/********************************************************************************
** Form generated from reading UI file 'contacts.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTS_H
#define UI_CONTACTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Contacts
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QTableView *tableView_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QWidget *tab_2;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_7;
    QTableView *tableView_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_23;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Contacts)
    {
        if (Contacts->objectName().isEmpty())
            Contacts->setObjectName(QStringLiteral("Contacts"));
        Contacts->resize(281, 505);
        centralwidget = new QWidget(Contacts);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 261, 461));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget_3 = new QWidget(tab);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 0, 251, 401));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        tableView_5 = new QTableView(layoutWidget_3);
        tableView_5->setObjectName(QStringLiteral("tableView_5"));

        verticalLayout_6->addWidget(tableView_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_17 = new QPushButton(layoutWidget_3);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/person_add-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(layoutWidget_3);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/person_cancel-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_18);

        pushButton_19 = new QPushButton(layoutWidget_3);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/user_woman_add-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton_19);

        pushButton_20 = new QPushButton(layoutWidget_3);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/grey_new_seo-26-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_20);


        verticalLayout_6->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget_4 = new QWidget(tab_2);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 0, 251, 401));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        tableView_6 = new QTableView(layoutWidget_4);
        tableView_6->setObjectName(QStringLiteral("tableView_6"));

        verticalLayout_7->addWidget(tableView_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_23 = new QPushButton(layoutWidget_4);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/user_group_users_delete_close-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_23->setIcon(icon4);

        horizontalLayout_6->addWidget(pushButton_23);


        verticalLayout_7->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        Contacts->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Contacts);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 281, 21));
        Contacts->setMenuBar(menubar);
        statusbar = new QStatusBar(Contacts);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Contacts->setStatusBar(statusbar);

        retranslateUi(Contacts);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Contacts);
    } // setupUi

    void retranslateUi(QMainWindow *Contacts)
    {
        Contacts->setWindowTitle(QApplication::translate("Contacts", "MainWindow", 0));
        label->setText(QApplication::translate("Contacts", "TextLabel", 0));
        pushButton_17->setText(QString());
        pushButton_18->setText(QString());
        pushButton_19->setText(QString());
        pushButton_20->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Contacts", "Chats", 0));
        pushButton_23->setText(QApplication::translate("Contacts", "Live group", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Contacts", "Groups", 0));
    } // retranslateUi

};

namespace Ui {
    class Contacts: public Ui_Contacts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTS_H
