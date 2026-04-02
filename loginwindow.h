#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "hotelsystem.h"

class LoginWindow : public QDialog {
    Q_OBJECT

    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *cancelButton;
    HotelSystem *hotel;
    QString expectedRole;

public:
    LoginWindow(HotelSystem *hotel, const QString &expectedRole, QWidget *parent = nullptr);

private slots:
    void attemptLogin();
    void handleLoginSuccess(User *user);
    void handleLoginFailed();
};

#endif
