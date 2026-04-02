#include "staffwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>


using namespace std;
using namespace Qt;

StaffWindow::StaffWindow(HotelSystem *hotel, const QString &username,
                         QWidget *parent)
    : QDialog(parent), hotel(hotel), username(username) {
  setWindowTitle("Staff Dashboard - Grand Horizon");
  resize(500, 400);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->setContentsMargins(30, 30, 30, 30);
  mainLayout->setSpacing(20);

  QLabel *headerLabel = new QLabel("Staff Dashboard", this);
  headerLabel->setStyleSheet(
      "font-size: 20px; font-weight: bold; color: #4A90E2;");
  headerLabel->setAlignment(Qt::AlignCenter);

  displayArea = new QTextEdit(this);
  displayArea->setReadOnly(true);
  displayArea->setStyleSheet("font-family: monospace; font-size: 13px;");

  QHBoxLayout *buttonLayout = new QHBoxLayout();
  viewInfoButton = new QPushButton("View My Information", this);
  logoutButton = new QPushButton("Logout / Back to Main", this);

  viewInfoButton->setMinimumHeight(40);
  logoutButton->setMinimumHeight(40);
  logoutButton->setStyleSheet(
      "background-color: #D32F2F; border-color: #B71C1C;");

  buttonLayout->addWidget(viewInfoButton);
  buttonLayout->addStretch();
  buttonLayout->addWidget(logoutButton);

  mainLayout->addWidget(headerLabel);
  mainLayout->addWidget(displayArea);
  mainLayout->addLayout(buttonLayout);

  connect(viewInfoButton, &QPushButton::clicked, this, &StaffWindow::viewInfo);
  connect(logoutButton, &QPushButton::clicked, this, &QDialog::accept);
}

void StaffWindow::viewInfo() {
  displayArea->setText(hotel->getStaffInfo(username));
}
