/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *btnAdmin;
    QPushButton *btnGuest;
    QWidget *page_3;
    QPushButton *btnLoginChoice;
    QPushButton *btnRegisterChoice;
    QWidget *page_4;
    QLineEdit *txtLoginUser;
    QLineEdit *txtLoginPass;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnLogin;
    QLabel *lblLoginStatus;
    QWidget *page_5;
    QLineEdit *txtName;
    QLineEdit *txtPhone;
    QLineEdit *txtAge;
    QLineEdit *txtEmail;
    QLineEdit *txtRegUser;
    QLineEdit *txtRegPass;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *btnRegister;
    QLabel *lblRegStatus;
    QWidget *page_2;
    QPushButton *btnViewCustomers;
    QPushButton *btnViewStaff;
    QPushButton *btnViewRooms;
    QPushButton *btnAddStaffPage;
    QPushButton *btnAddRoomPage;
    QWidget *page_6;
    QTextEdit *textCustomers;
    QPushButton *btnBackFromCustomers;
    QWidget *page_7;
    QTextEdit *textStaff;
    QPushButton *btnBackFromStaff;
    QWidget *page_8;
    QPlainTextEdit *textRooms;
    QPushButton *btnBackFromRooms;
    QWidget *page_9;
    QLineEdit *txtStaffName;
    QLineEdit *txtStaffPhone;
    QLineEdit *txtStaffSalary;
    QLineEdit *txtStaffPosition;
    QLineEdit *txtStaffShift;
    QPushButton *btnBackFromAddStaff;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *btnAddStaff;
    QWidget *page_10;
    QPushButton *btnAddRoom;
    QPushButton *btnBackFromAddRoom;
    QLineEdit *txtRoomNumber;
    QLineEdit *txtRoomType;
    QLineEdit *txtRoomRent;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(350, 180, 261, 251));
        page = new QWidget();
        page->setObjectName("page");
        btnAdmin = new QPushButton(page);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setGeometry(QRect(30, 50, 56, 18));
        btnGuest = new QPushButton(page);
        btnGuest->setObjectName("btnGuest");
        btnGuest->setGeometry(QRect(140, 50, 56, 18));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        btnLoginChoice = new QPushButton(page_3);
        btnLoginChoice->setObjectName("btnLoginChoice");
        btnLoginChoice->setGeometry(QRect(30, 50, 56, 18));
        btnRegisterChoice = new QPushButton(page_3);
        btnRegisterChoice->setObjectName("btnRegisterChoice");
        btnRegisterChoice->setGeometry(QRect(140, 50, 56, 18));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        txtLoginUser = new QLineEdit(page_4);
        txtLoginUser->setObjectName("txtLoginUser");
        txtLoginUser->setGeometry(QRect(90, 20, 113, 20));
        txtLoginPass = new QLineEdit(page_4);
        txtLoginPass->setObjectName("txtLoginPass");
        txtLoginPass->setGeometry(QRect(90, 60, 113, 20));
        label = new QLabel(page_4);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 51, 20));
        label_2 = new QLabel(page_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 51, 20));
        btnLogin = new QPushButton(page_4);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(110, 100, 56, 18));
        lblLoginStatus = new QLabel(page_4);
        lblLoginStatus->setObjectName("lblLoginStatus");
        lblLoginStatus->setGeometry(QRect(66, 120, 131, 20));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        txtName = new QLineEdit(page_5);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(110, 10, 113, 20));
        txtPhone = new QLineEdit(page_5);
        txtPhone->setObjectName("txtPhone");
        txtPhone->setGeometry(QRect(110, 40, 113, 20));
        txtAge = new QLineEdit(page_5);
        txtAge->setObjectName("txtAge");
        txtAge->setGeometry(QRect(110, 70, 113, 20));
        txtEmail = new QLineEdit(page_5);
        txtEmail->setObjectName("txtEmail");
        txtEmail->setGeometry(QRect(110, 100, 113, 20));
        txtRegUser = new QLineEdit(page_5);
        txtRegUser->setObjectName("txtRegUser");
        txtRegUser->setGeometry(QRect(110, 130, 113, 20));
        txtRegPass = new QLineEdit(page_5);
        txtRegPass->setObjectName("txtRegPass");
        txtRegPass->setGeometry(QRect(110, 160, 113, 20));
        label_3 = new QLabel(page_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 10, 41, 16));
        label_4 = new QLabel(page_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 40, 37, 12));
        label_5 = new QLabel(page_5);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 70, 37, 12));
        label_6 = new QLabel(page_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 100, 37, 12));
        label_7 = new QLabel(page_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(46, 130, 41, 20));
        label_8 = new QLabel(page_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 160, 37, 12));
        btnRegister = new QPushButton(page_5);
        btnRegister->setObjectName("btnRegister");
        btnRegister->setGeometry(QRect(130, 200, 56, 18));
        lblRegStatus = new QLabel(page_5);
        lblRegStatus->setObjectName("lblRegStatus");
        lblRegStatus->setGeometry(QRect(56, 230, 171, 20));
        stackedWidget->addWidget(page_5);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        btnViewCustomers = new QPushButton(page_2);
        btnViewCustomers->setObjectName("btnViewCustomers");
        btnViewCustomers->setGeometry(QRect(80, 30, 91, 18));
        btnViewStaff = new QPushButton(page_2);
        btnViewStaff->setObjectName("btnViewStaff");
        btnViewStaff->setGeometry(QRect(80, 60, 91, 20));
        btnViewRooms = new QPushButton(page_2);
        btnViewRooms->setObjectName("btnViewRooms");
        btnViewRooms->setGeometry(QRect(80, 90, 91, 20));
        btnAddStaffPage = new QPushButton(page_2);
        btnAddStaffPage->setObjectName("btnAddStaffPage");
        btnAddStaffPage->setGeometry(QRect(80, 120, 91, 20));
        btnAddRoomPage = new QPushButton(page_2);
        btnAddRoomPage->setObjectName("btnAddRoomPage");
        btnAddRoomPage->setGeometry(QRect(80, 150, 91, 20));
        stackedWidget->addWidget(page_2);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        textCustomers = new QTextEdit(page_6);
        textCustomers->setObjectName("textCustomers");
        textCustomers->setGeometry(QRect(-7, 20, 221, 131));
        btnBackFromCustomers = new QPushButton(page_6);
        btnBackFromCustomers->setObjectName("btnBackFromCustomers");
        btnBackFromCustomers->setGeometry(QRect(90, 160, 56, 18));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        textStaff = new QTextEdit(page_7);
        textStaff->setObjectName("textStaff");
        textStaff->setGeometry(QRect(60, 25, 151, 91));
        btnBackFromStaff = new QPushButton(page_7);
        btnBackFromStaff->setObjectName("btnBackFromStaff");
        btnBackFromStaff->setGeometry(QRect(110, 140, 56, 18));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        textRooms = new QPlainTextEdit(page_8);
        textRooms->setObjectName("textRooms");
        textRooms->setGeometry(QRect(53, 40, 141, 91));
        btnBackFromRooms = new QPushButton(page_8);
        btnBackFromRooms->setObjectName("btnBackFromRooms");
        btnBackFromRooms->setGeometry(QRect(90, 150, 56, 18));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        txtStaffName = new QLineEdit(page_9);
        txtStaffName->setObjectName("txtStaffName");
        txtStaffName->setGeometry(QRect(80, 30, 113, 20));
        txtStaffPhone = new QLineEdit(page_9);
        txtStaffPhone->setObjectName("txtStaffPhone");
        txtStaffPhone->setGeometry(QRect(80, 60, 113, 20));
        txtStaffSalary = new QLineEdit(page_9);
        txtStaffSalary->setObjectName("txtStaffSalary");
        txtStaffSalary->setGeometry(QRect(80, 90, 113, 20));
        txtStaffPosition = new QLineEdit(page_9);
        txtStaffPosition->setObjectName("txtStaffPosition");
        txtStaffPosition->setGeometry(QRect(80, 130, 113, 20));
        txtStaffShift = new QLineEdit(page_9);
        txtStaffShift->setObjectName("txtStaffShift");
        txtStaffShift->setGeometry(QRect(80, 160, 113, 20));
        btnBackFromAddStaff = new QPushButton(page_9);
        btnBackFromAddStaff->setObjectName("btnBackFromAddStaff");
        btnBackFromAddStaff->setGeometry(QRect(90, 230, 56, 18));
        label_9 = new QLabel(page_9);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 30, 37, 12));
        label_10 = new QLabel(page_9);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 60, 37, 12));
        label_11 = new QLabel(page_9);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 90, 37, 12));
        label_12 = new QLabel(page_9);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 130, 37, 12));
        label_13 = new QLabel(page_9);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 170, 37, 12));
        btnAddStaff = new QPushButton(page_9);
        btnAddStaff->setObjectName("btnAddStaff");
        btnAddStaff->setGeometry(QRect(90, 200, 56, 18));
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        btnAddRoom = new QPushButton(page_10);
        btnAddRoom->setObjectName("btnAddRoom");
        btnAddRoom->setGeometry(QRect(85, 140, 81, 20));
        btnBackFromAddRoom = new QPushButton(page_10);
        btnBackFromAddRoom->setObjectName("btnBackFromAddRoom");
        btnBackFromAddRoom->setGeometry(QRect(85, 180, 81, 20));
        txtRoomNumber = new QLineEdit(page_10);
        txtRoomNumber->setObjectName("txtRoomNumber");
        txtRoomNumber->setGeometry(QRect(80, 20, 113, 20));
        txtRoomType = new QLineEdit(page_10);
        txtRoomType->setObjectName("txtRoomType");
        txtRoomType->setGeometry(QRect(80, 50, 113, 20));
        txtRoomRent = new QLineEdit(page_10);
        txtRoomRent->setObjectName("txtRoomRent");
        txtRoomRent->setGeometry(QRect(80, 90, 113, 20));
        label_14 = new QLabel(page_10);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(6, 20, 61, 21));
        label_15 = new QLabel(page_10);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 50, 51, 20));
        label_16 = new QLabel(page_10);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 90, 51, 20));
        stackedWidget->addWidget(page_10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(9);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAdmin->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        btnGuest->setText(QCoreApplication::translate("MainWindow", "Guest", nullptr));
        btnLoginChoice->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        btnRegisterChoice->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        lblLoginStatus->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Phone:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Age:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        btnRegister->setText(QCoreApplication::translate("MainWindow", "REGISTER", nullptr));
        lblRegStatus->setText(QString());
        btnViewCustomers->setText(QCoreApplication::translate("MainWindow", "View Customer", nullptr));
        btnViewStaff->setText(QCoreApplication::translate("MainWindow", "View Staff", nullptr));
        btnViewRooms->setText(QCoreApplication::translate("MainWindow", "View Rooms", nullptr));
        btnAddStaffPage->setText(QCoreApplication::translate("MainWindow", "Add staff", nullptr));
        btnAddRoomPage->setText(QCoreApplication::translate("MainWindow", "Add Room", nullptr));
        btnBackFromCustomers->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnBackFromStaff->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnBackFromRooms->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnBackFromAddStaff->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Phone:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Salary:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Position:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        btnAddStaff->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        btnAddRoom->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        btnBackFromAddRoom->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Room Number:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Room type:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Room Rent:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
