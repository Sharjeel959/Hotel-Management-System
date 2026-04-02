#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include "hotelsystem.h"
#include <QComboBox>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class RegisterWindow : public QDialog {
  Q_OBJECT
  HotelSystem *hotel;
  QComboBox *roleCombo;
  QLineEdit *nameEdit;
  QLineEdit *phoneEdit;
  QLineEdit *usernameEdit;
  QLineEdit *passwordEdit;
  QLineEdit *emailEdit;
  QLineEdit *positionEdit;
  QComboBox *shiftCombo;
  QLineEdit *salaryEdit;
  QPushButton *registerButton;
  QPushButton *cancelButton;

public:
  RegisterWindow(HotelSystem *hotel, QWidget *parent = nullptr);
  void setFixedRole(const QString &role);

private slots:
  void updateForm();
  void attemptRegister();
  void handleRegistrationSuccess();
  void handleRegistrationFailed();
};

#endif
