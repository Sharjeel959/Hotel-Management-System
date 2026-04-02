#include "registerwindow.h"
#include <QComboBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QRegularExpressionValidator>
#include <QDoubleValidator>

using namespace std;
using namespace Qt;

RegisterWindow::RegisterWindow(HotelSystem *hotel, QWidget *parent)
    : QDialog(parent), hotel(hotel) {
  setWindowTitle("Register - Grand Horizon");
  resize(400, 500);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->setContentsMargins(30, 30, 30, 30);
  mainLayout->setSpacing(20);

  QLabel *headerLabel = new QLabel("Create an Account", this);
  headerLabel->setStyleSheet(
      "font-size: 20px; font-weight: bold; color: #FFFFFF;");
  headerLabel->setAlignment(Qt::AlignCenter);

  QFormLayout *formLayout = new QFormLayout();
  formLayout->setSpacing(15);
  formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

  roleCombo = new QComboBox(this);
  roleCombo->addItems({"admin", "guest"});
  roleCombo->setMinimumHeight(35);

  nameEdit = new QLineEdit(this);
  nameEdit->setPlaceholderText("Full Name");
  nameEdit->setMinimumHeight(35);
  nameEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z ]+$"), this));

  phoneEdit = new QLineEdit(this);
  phoneEdit->setPlaceholderText("Phone Number");
  phoneEdit->setMinimumHeight(35);
  phoneEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^\\+?[0-9]{10,15}$"), this));

  usernameEdit = new QLineEdit(this);
  usernameEdit->setPlaceholderText("Username");
  usernameEdit->setMinimumHeight(35);

  passwordEdit = new QLineEdit(this);
  passwordEdit->setPlaceholderText("Password");
  passwordEdit->setEchoMode(QLineEdit::Password);
  passwordEdit->setMinimumHeight(35);

  emailEdit = new QLineEdit(this);
  emailEdit->setPlaceholderText("Email Address");
  emailEdit->setMinimumHeight(35);
  emailEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$"), this));

  formLayout->addRow("Account Role:", roleCombo);
  formLayout->addRow("Name:", nameEdit);
  formLayout->addRow("Phone:", phoneEdit);
  formLayout->addRow("Username:", usernameEdit);
  formLayout->addRow("Password:", passwordEdit);
  formLayout->addRow("Email:", emailEdit);

  QHBoxLayout *buttonLayout = new QHBoxLayout();
  registerButton = new QPushButton("Register", this);
  cancelButton = new QPushButton("Cancel", this);
  registerButton->setMinimumHeight(40);
  cancelButton->setMinimumHeight(40);
  cancelButton->setStyleSheet(
      "background-color: #555555; border-color: #444444;");

  buttonLayout->addWidget(cancelButton);
  buttonLayout->addWidget(registerButton);

  mainLayout->addWidget(headerLabel);
  mainLayout->addLayout(formLayout);
  mainLayout->addStretch();
  mainLayout->addLayout(buttonLayout);

  updateForm();
  connect(roleCombo, &QComboBox::currentTextChanged, this,
          &RegisterWindow::updateForm);
  connect(registerButton, &QPushButton::clicked, this,
          &RegisterWindow::attemptRegister);
  connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
  connect(hotel, &HotelSystem::registrationSuccess, this,
          &RegisterWindow::handleRegistrationSuccess);
  connect(hotel, &HotelSystem::registrationFailed, this,
          &RegisterWindow::handleRegistrationFailed);
}

void RegisterWindow::updateForm() {
  // Email is now visible for all roles to prevent UI glitches with labels
}

void RegisterWindow::attemptRegister() {
  QString role = roleCombo->currentText();

  if (nameEdit->text().trimmed().isEmpty() || 
      phoneEdit->text().trimmed().isEmpty() || 
      usernameEdit->text().trimmed().isEmpty() || 
      passwordEdit->text().trimmed().isEmpty()) {
    QMessageBox::warning(this, "Validation Error", "Please fill in all required fields.");
    return;
  }

  if (role == "guest" && emailEdit->text().trimmed().isEmpty()) {
    QMessageBox::warning(this, "Validation Error", "Email is required for guests.");
    return;
  }

  if (!nameEdit->hasAcceptableInput()) {
    QMessageBox::warning(this, "Validation Error", "Please enter a valid name (letters and spaces only).");
    return;
  }
  
  if (!phoneEdit->hasAcceptableInput()) {
    QMessageBox::warning(this, "Validation Error", "Please enter a valid phone number (10-15 digits, optional +).");
    return;
  }

  if (role == "guest" && !emailEdit->hasAcceptableInput()) {
    QMessageBox::warning(this, "Validation Error", "Please enter a valid email address.");
    return;
  }

  bool success = hotel->registerUser(role, nameEdit->text(), phoneEdit->text(),
                      usernameEdit->text(), passwordEdit->text(),
                      emailEdit->text(), "", "", 0.0f);
  if (!success) {
      handleRegistrationFailed();
  }
}

void RegisterWindow::handleRegistrationSuccess() {
  QMessageBox::information(this, "Success", "Registration successful!");
  accept();
}

void RegisterWindow::handleRegistrationFailed() {
  QMessageBox::warning(
      this, "Error",
      "Registration failed. Check input or username availability.");
}

void RegisterWindow::setFixedRole(const QString &role) {
  int index = roleCombo->findText(role);
  if (index >= 0) {
    roleCombo->setCurrentIndex(index);
    roleCombo->setEnabled(false);
  }
}
