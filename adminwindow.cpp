#include "adminwindow.h"
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QStackedWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>


using namespace std;
using namespace Qt;

AdminWindow::AdminWindow(HotelSystem *hotel, QWidget *parent)
    : QDialog(parent), hotel(hotel) {
  setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
  setWindowTitle("Admin Dashboard - Grand Horizon");
  resize(1050, 680);
  showMaximized();

  QHBoxLayout *mainLayout = new QHBoxLayout(this);
  mainLayout->setContentsMargins(20, 20, 20, 20);
  mainLayout->setSpacing(20);

  // Sidebar Layout (Left side)
  QVBoxLayout *sidebarLayout = new QVBoxLayout();
  sidebarLayout->setSpacing(15);

  QLabel *headerLabel = new QLabel("Admin Panel", this);
  headerLabel->setStyleSheet(
      "font-size: 22px; font-weight: bold; color: #4A90E2;");
  headerLabel->setAlignment(Qt::AlignCenter);

  QPushButton *dashboardButton = new QPushButton("Dashboard", this);
  viewCustomersButton = new QPushButton("Customer Bookings", this);
  viewStaffButton = new QPushButton("Manage Staff", this);
  viewRoomsButton = new QPushButton("Manage Rooms", this);
  logoutButton = new QPushButton("Logout / Back to Main", this);

  dashboardButton->setProperty("class", "nav");
  viewCustomersButton->setProperty("class", "nav");
  viewStaffButton->setProperty("class", "nav");
  viewRoomsButton->setProperty("class", "nav");
  logoutButton->setProperty("class", "logout");

  sidebarLayout->addWidget(headerLabel);
  sidebarLayout->addSpacing(10);
  sidebarLayout->addWidget(dashboardButton);
  sidebarLayout->addWidget(viewCustomersButton);
  sidebarLayout->addWidget(viewStaffButton);
  sidebarLayout->addWidget(viewRoomsButton);
  sidebarLayout->addStretch();
  sidebarLayout->addWidget(logoutButton);

  // Main Content Area (Right side)
  stackedWidget = new QStackedWidget(this);

  // 1. Dashboard Page
  dashboardPage = new QWidget();
  QVBoxLayout *dashLayout = new QVBoxLayout(dashboardPage);
  QLabel *dashTitle = new QLabel("System Overview", dashboardPage);
  dashTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  QFormLayout *statsLayout = new QFormLayout();
  totalGuestsLabel = new QLabel("0", dashboardPage);
  totalStaffLabel = new QLabel("0", dashboardPage);
  totalRoomsLabel = new QLabel("0", dashboardPage);
  bookedRoomsLabel = new QLabel("0", dashboardPage);
  earningsLabel = new QLabel("$0.00", dashboardPage);
  
  statsLayout->addRow("Total Guests:", totalGuestsLabel);
  statsLayout->addRow("Total Staff:", totalStaffLabel);
  statsLayout->addRow("Total Rooms:", totalRoomsLabel);
  statsLayout->addRow("Booked Rooms:", bookedRoomsLabel);
  statsLayout->addRow("Estimated Earnings:", earningsLabel);

  dashLayout->addWidget(dashTitle);
  dashLayout->addLayout(statsLayout);
  dashLayout->addStretch();

  // 2. Customers Page
  customersPage = new QWidget();
  QVBoxLayout *custLayout = new QVBoxLayout(customersPage);
  QLabel *custTitle = new QLabel("Customer Bookings", customersPage);
  custTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  QHBoxLayout *custBtnLayout = new QHBoxLayout();
  editCustomerButton = new QPushButton("Edit Customer Data", customersPage);
  forceCheckoutButton = new QPushButton("Force Checkout", customersPage);
  forceCheckoutButton->setProperty("class", "danger");
  custBtnLayout->addWidget(editCustomerButton);
  custBtnLayout->addWidget(forceCheckoutButton);
  
  customersTable = new QTableWidget(0, 4, customersPage);
  customersTable->setHorizontalHeaderLabels({"Name", "Phone", "Email", "Booked Room"});
  customersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  custLayout->addWidget(custTitle);
  custLayout->addLayout(custBtnLayout);
  custLayout->addWidget(customersTable);

  // 3. Staff Page
  staffPage = new QWidget();
  QVBoxLayout *staffLayout = new QVBoxLayout(staffPage);
  QLabel *staffTitle = new QLabel("Staff Management", staffPage);
  staffTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  QHBoxLayout *staffBtnLayout = new QHBoxLayout();
  addStaffButton = new QPushButton("Add New Staff", staffPage);
  editStaffButton = new QPushButton("Edit Staff Member", staffPage);
  staffBtnLayout->addWidget(addStaffButton);
  staffBtnLayout->addWidget(editStaffButton);
  
  staffTable = new QTableWidget(0, 4, staffPage);
  staffTable->setHorizontalHeaderLabels({"Name", "Position", "Shift", "Salary"});
  staffTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  staffLayout->addWidget(staffTitle);
  staffLayout->addLayout(staffBtnLayout);
  staffLayout->addWidget(staffTable);

  // 4. Rooms Page
  roomsPage = new QWidget();
  QVBoxLayout *roomsLayout = new QVBoxLayout(roomsPage);
  QLabel *roomsTitle = new QLabel("Room Management", roomsPage);
  roomsTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  QHBoxLayout *roomBtnLayout = new QHBoxLayout();
  addRoomButton = new QPushButton("Add New Room", roomsPage);
  toggleRoomButton = new QPushButton("Toggle Room Status", roomsPage);
  roomBtnLayout->addWidget(addRoomButton);
  roomBtnLayout->addWidget(toggleRoomButton);
  
  roomsTable = new QTableWidget(0, 4, roomsPage);
  roomsTable->setHorizontalHeaderLabels({"Room No.", "Type", "Price", "Status"});
  roomsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  roomsLayout->addWidget(roomsTitle);
  roomsLayout->addLayout(roomBtnLayout);
  roomsLayout->addWidget(roomsTable);

  // 5. Feedback Page
  feedbackPage = new QWidget();
  QVBoxLayout *feedbackLayout = new QVBoxLayout(feedbackPage);
  QLabel *feedbackTitle = new QLabel("Guest Feedback", feedbackPage);
  feedbackTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  deleteFeedbackButton = new QPushButton("Delete Selected Feedback", feedbackPage);
  feedbackTable = new QTableWidget(0, 3, feedbackPage);
  feedbackTable->setHorizontalHeaderLabels({"Username", "Comment", "Rating"});
  feedbackTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  
  feedbackLayout->addWidget(feedbackTitle);
  feedbackLayout->addWidget(deleteFeedbackButton);
  feedbackLayout->addWidget(feedbackTable);

  // 6. Housekeeping Page
  housekeepingPage = new QWidget();
  QVBoxLayout *hkLayout = new QVBoxLayout(housekeepingPage);
  QLabel *hkTitle = new QLabel("Housekeeping Status", housekeepingPage);
  hkTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  markCleanedButton = new QPushButton("Mark Room as Cleaned", housekeepingPage);
  housekeepingTable = new QTableWidget(0, 2, housekeepingPage);
  housekeepingTable->setHorizontalHeaderLabels({"Room No.", "Type"});
  housekeepingTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  
  hkLayout->addWidget(hkTitle);
  hkLayout->addWidget(markCleanedButton);
  hkLayout->addWidget(housekeepingTable);

  stackedWidget->addWidget(dashboardPage); // Index 0
  stackedWidget->addWidget(customersPage); // Index 1
  stackedWidget->addWidget(staffPage);     // Index 2
  stackedWidget->addWidget(roomsPage);     // Index 3
  stackedWidget->addWidget(feedbackPage);  // Index 4
  stackedWidget->addWidget(housekeepingPage); // Index 5

  mainLayout->addLayout(sidebarLayout, 1);
  mainLayout->addWidget(stackedWidget, 3); // Display area takes more space

  viewFeedbackMainButton = new QPushButton("Manage Feedback", this);
  viewHousekeepingMainButton = new QPushButton("Housekeeping", this);
  viewFeedbackMainButton->setProperty("class", "nav");
  viewHousekeepingMainButton->setProperty("class", "nav");
  sidebarLayout->insertWidget(5, viewFeedbackMainButton);
  sidebarLayout->insertWidget(6, viewHousekeepingMainButton);

  // Navigation Connections
  connect(dashboardButton, &QPushButton::clicked, this, &AdminWindow::showDashboard);
  connect(viewCustomersButton, &QPushButton::clicked, this, &AdminWindow::showCustomers);
  connect(viewStaffButton, &QPushButton::clicked, this, &AdminWindow::showStaff);
  connect(viewRoomsButton, &QPushButton::clicked, this, &AdminWindow::showRooms);
  connect(viewFeedbackMainButton, &QPushButton::clicked, this, &AdminWindow::showFeedback);
  connect(viewHousekeepingMainButton, &QPushButton::clicked, this, &AdminWindow::showHousekeeping);
  
  // Action Connections
  connect(editCustomerButton, &QPushButton::clicked, this, &AdminWindow::editCustomer);
  connect(forceCheckoutButton, &QPushButton::clicked, this, &AdminWindow::forceCheckout);
  connect(editStaffButton, &QPushButton::clicked, this, &AdminWindow::editStaff);
  connect(toggleRoomButton, &QPushButton::clicked, this, &AdminWindow::toggleRoomStatus);
  connect(addStaffButton, &QPushButton::clicked, this, &AdminWindow::addStaff);
  connect(addRoomButton, &QPushButton::clicked, this, &AdminWindow::addRoom);
  connect(deleteFeedbackButton, &QPushButton::clicked, this, &AdminWindow::deleteFeedback);
  connect(markCleanedButton, &QPushButton::clicked, this, &AdminWindow::markCleaned);
  connect(logoutButton, &QPushButton::clicked, this, &QDialog::accept);

  showDashboard(); // Default view
}

void AdminWindow::animatePageChange(int index) {
    if (stackedWidget->currentIndex() == index) return;
    
    // Apply opacity effect
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(stackedWidget->widget(index));
    stackedWidget->widget(index)->setGraphicsEffect(effect);
    
    stackedWidget->setCurrentIndex(index);
    
    // Animate opacity from 0 to 1
    QPropertyAnimation *anim = new QPropertyAnimation(effect, "opacity");
    anim->setDuration(300); // 300 ms fade
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void AdminWindow::showDashboard() { updateDashboardStats(); animatePageChange(0); }
void AdminWindow::showCustomers() { animatePageChange(1); refreshCustomersTable(); }
void AdminWindow::showStaff() { animatePageChange(2); refreshStaffTable(); }
void AdminWindow::showRooms() { animatePageChange(3); refreshRoomsTable(); }
void AdminWindow::showFeedback() { animatePageChange(4); refreshFeedbackTable(); }
void AdminWindow::showHousekeeping() { animatePageChange(5); refreshHousekeepingTable(); }

void AdminWindow::updateDashboardStats() {
    totalGuestsLabel->setText(QString::number(hotel->getTotalGuests()));
    totalStaffLabel->setText(QString::number(hotel->getTotalStaff()));
    totalRoomsLabel->setText(QString::number(hotel->getTotalRooms()));
    bookedRoomsLabel->setText(QString::number(hotel->getBookedRoomsCount()));
    earningsLabel->setText("$" + QString::number(hotel->calculateEstimatedEarnings(), 'f', 2));
}

void AdminWindow::refreshCustomersTable() {
  QString data = hotel->getCustomers();
  QStringList lines = data.split("\n", Qt::SkipEmptyParts);
  customersTable->setRowCount(lines.size());
  for (int i = 0; i < lines.size(); ++i) {
    QStringList fields = lines[i].split(" | ");
    if (fields.size() >= 3) {
      customersTable->setItem(i, 0, new QTableWidgetItem(fields[0]));
      customersTable->setItem(i, 1, new QTableWidgetItem(fields[1]));
      customersTable->setItem(i, 2, new QTableWidgetItem(fields[2]));
      // The 4th column should be exactly which room they booked, which we will extract by searching guest data.
      Guest *g = hotel->findGuestByUsername(fields[0]);
      if (g && g->getRoomNumber() > 0) {
        customersTable->setItem(i, 3, new QTableWidgetItem(QString::number(g->getRoomNumber())));
      } else {
        customersTable->setItem(i, 3, new QTableWidgetItem("None"));
      }
    }
  }
}

void AdminWindow::refreshStaffTable() {
  QString data = hotel->getStaff();
  QStringList lines = data.split("\n", Qt::SkipEmptyParts);
  staffTable->setRowCount(lines.size());
  for (int i = 0; i < lines.size(); ++i) {
    QStringList fields = lines[i].split(" | ");
    if (fields.size() >= 3) {
      staffTable->setItem(i, 0, new QTableWidgetItem(fields[0]));
      staffTable->setItem(i, 1, new QTableWidgetItem(fields[1]));
      
      Staff *s = hotel->findStaffByUsername(fields[0]);
      if (s) {
          staffTable->setItem(i, 2, new QTableWidgetItem(s->getShift()));
      } else {
          staffTable->setItem(i, 2, new QTableWidgetItem("N/A"));
      }
      staffTable->setItem(i, 3, new QTableWidgetItem("$" + fields[2]));
    }
  }
}

void AdminWindow::refreshRoomsTable() {
  QString data = hotel->getRooms();
  QStringList lines = data.split("\n", Qt::SkipEmptyParts);
  roomsTable->setRowCount(lines.size());
  for (int i = 0; i < lines.size(); ++i) {
    QStringList fields = lines[i].split(" | ");
    if (fields.size() >= 3) {
      roomsTable->setItem(i, 0, new QTableWidgetItem(fields[0]));
      roomsTable->setItem(i, 1, new QTableWidgetItem(fields[1].toUpper()));
      roomsTable->setItem(i, 2, new QTableWidgetItem("$" + fields[2]));
      
      Room *r = hotel->findRoomByNumber(fields[0].toInt());
      if (r) {
          if (!r->isAvailable()) {
              QTableWidgetItem *statusItem = new QTableWidgetItem("Booked by: " + r->getBookedBy());
              statusItem->setForeground(QBrush(QColor("#D32F2F")));
              roomsTable->setItem(i, 3, statusItem);
          } else {
               QTableWidgetItem *statusItem = new QTableWidgetItem("Available");
               statusItem->setForeground(QBrush(QColor("#388E3C")));
               roomsTable->setItem(i, 3, statusItem);
          }
      }
    }
  }
}



void AdminWindow::addStaff() {
  QDialog dialog(this);
  dialog.setWindowTitle("Add New Staff");
  dialog.resize(350, 400);
  
  QVBoxLayout layout(&dialog);
  layout.setContentsMargins(20, 20, 20, 20);
  
  QLabel *title = new QLabel("Staff Details", &dialog);
  title->setStyleSheet("font-size: 18px; font-weight: bold; color: #4A90E2; margin-bottom: 10px;");
  layout.addWidget(title);

  QFormLayout formLayout;
  QLineEdit *nameEdit = new QLineEdit(&dialog);
  QLineEdit *phoneEdit = new QLineEdit(&dialog);
  QLineEdit *positionEdit = new QLineEdit(&dialog);
  QComboBox *shiftCombo = new QComboBox(&dialog);
  shiftCombo->addItems({"morning", "evening", "night"});
  QLineEdit *salaryEdit = new QLineEdit(&dialog);
  
  formLayout.addRow("Full Name:", nameEdit);
  formLayout.addRow("Phone Number:", phoneEdit);
  formLayout.addRow("Position:", positionEdit);
  formLayout.addRow("Shift:", shiftCombo);
  formLayout.addRow("Salary:", salaryEdit);
  
  layout.addLayout(&formLayout);
  
  QHBoxLayout btns;
  QPushButton submitBtn("Add Staff", &dialog);
  QPushButton cancelBtn("Cancel", &dialog);
  cancelBtn.setStyleSheet("background-color: #555555;");
  
  btns.addWidget(&cancelBtn);
  btns.addWidget(&submitBtn);
  layout.addLayout(&btns);
  
  connect(&cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);
  connect(&submitBtn, &QPushButton::clicked, [&]() {
    if (nameEdit->text().isEmpty() || phoneEdit->text().isEmpty() || 
        positionEdit->text().isEmpty() || salaryEdit->text().isEmpty()) {
       QMessageBox::warning(&dialog, "Error", "All fields are required.");
       return;
    }
    bool ok;
    float salary = salaryEdit->text().toFloat(&ok);
    if (!ok) {
       QMessageBox::warning(&dialog, "Error", "Invalid salary format.");
       return;
    }
    if (hotel->addStaff(nameEdit->text(), phoneEdit->text(), positionEdit->text(), shiftCombo->currentText(), salary)) {
      QMessageBox::information(&dialog, "Success", "Staff added successfully!");
      refreshStaffTable();
      dialog.accept();
    } else {
      QMessageBox::warning(&dialog, "Error", "Failed to add staff.");
    }
  });
  
  dialog.exec();
}



void AdminWindow::addRoom() {
  QDialog dialog(this);
  dialog.setWindowTitle("Add New Room");
  dialog.resize(300, 250);
  
  QVBoxLayout layout(&dialog);
  layout.setContentsMargins(20, 20, 20, 20);
  
  QLabel *title = new QLabel("Room Details", &dialog);
  title->setStyleSheet("font-size: 18px; font-weight: bold; color: #4A90E2; margin-bottom: 10px;");
  layout.addWidget(title);

  QFormLayout formLayout;
  QLineEdit *numberEdit = new QLineEdit(&dialog);
  QComboBox *typeCombo = new QComboBox(&dialog);
  typeCombo->addItems({"single", "double"});
  QLineEdit *priceEdit = new QLineEdit(&dialog);
  
  formLayout.addRow("Room Number:", numberEdit);
  formLayout.addRow("Type:", typeCombo);
  formLayout.addRow("Price per Night:", priceEdit);
  
  layout.addLayout(&formLayout);
  
  QHBoxLayout btns;
  QPushButton submitBtn("Add Room", &dialog);
  QPushButton cancelBtn("Cancel", &dialog);
  cancelBtn.setStyleSheet("background-color: #555555;");
  
  btns.addWidget(&cancelBtn);
  btns.addWidget(&submitBtn);
  layout.addLayout(&btns);
  
  connect(&cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);
  connect(&submitBtn, &QPushButton::clicked, [&]() {
    if (numberEdit->text().isEmpty() || priceEdit->text().isEmpty()) {
       QMessageBox::warning(&dialog, "Error", "All fields are required.");
       return;
    }
    bool okNum, okPrice;
    int number = numberEdit->text().toInt(&okNum);
    float price = priceEdit->text().toFloat(&okPrice);
    if (!okNum || !okPrice) {
       QMessageBox::warning(&dialog, "Error", "Invalid number or price format.");
       return;
    }
    if (hotel->addRoom(number, typeCombo->currentText(), price)) {
      QMessageBox::information(&dialog, "Success", "Room added successfully!");
      refreshRoomsTable();
      dialog.accept();
    } else {
      QMessageBox::warning(&dialog, "Error", "Failed to add room.");
    }
  });
  
  dialog.exec();
}

void AdminWindow::editCustomer() {
    bool ok;
    QString username = QInputDialog::getText(this, "Edit Customer", "Enter Customer Name to Edit:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;
    
    Guest* g = hotel->findGuestByUsername(username);
    if (!g) {
        QMessageBox::warning(this, "Not Found", "Customer not found in system.");
        return;
    }
    
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Customer: " + username);
    dialog.resize(350, 250);
    QVBoxLayout layout(&dialog);
    QFormLayout form;
    QLineEdit *emailEdit = new QLineEdit(&dialog);
    emailEdit->setText(g->getEmail());
    QLineEdit *phoneEdit = new QLineEdit(&dialog);
    phoneEdit->setText(g->getPhone());
    
    form.addRow("New Email:", emailEdit);
    form.addRow("New Phone:", phoneEdit);
    layout.addLayout(&form);
    
    QHBoxLayout btns;
    QPushButton submitBtn("Save Changes", &dialog);
    QPushButton cancelBtn("Cancel", &dialog);
    cancelBtn.setStyleSheet("background-color: #555555;");
    btns.addWidget(&cancelBtn);
    btns.addWidget(&submitBtn);
    layout.addLayout(&btns);
    
    connect(&cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&submitBtn, &QPushButton::clicked, [&]() {
        hotel->updateCustomer(username, emailEdit->text(), phoneEdit->text());
        QMessageBox::information(&dialog, "Success", "Customer updated successfully!");
        refreshCustomersTable();
        dialog.accept();
    });
    dialog.exec();
}

void AdminWindow::editStaff() {
    bool ok;
    QString username = QInputDialog::getText(this, "Edit Staff", "Enter Staff Name to Edit:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;
    
    Staff* s = hotel->findStaffByUsername(username);
    if (!s) {
        QMessageBox::warning(this, "Not Found", "Staff not found in system.");
        return;
    }
    
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Staff: " + username);
    dialog.resize(350, 300);
    QVBoxLayout layout(&dialog);
    QFormLayout form;
    QLineEdit *posEdit = new QLineEdit(&dialog);
    posEdit->setText(s->getPosition());
    QComboBox *shiftCombo = new QComboBox(&dialog);
    shiftCombo->addItems({"morning", "evening", "night"});
    shiftCombo->setCurrentText(s->getShift());
    QLineEdit *salEdit = new QLineEdit(&dialog);
    salEdit->setText(QString::number(s->getSalary()));
    
    form.addRow("New Position:", posEdit);
    form.addRow("New Shift:", shiftCombo);
    form.addRow("New Salary:", salEdit);
    layout.addLayout(&form);
    
    QHBoxLayout btns;
    QPushButton submitBtn("Save Changes", &dialog);
    QPushButton cancelBtn("Cancel", &dialog);
    cancelBtn.setStyleSheet("background-color: #555555;");
    btns.addWidget(&cancelBtn);
    btns.addWidget(&submitBtn);
    layout.addLayout(&btns);
    
    connect(&cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&submitBtn, &QPushButton::clicked, [&]() {
        hotel->updateStaff(username, posEdit->text(), shiftCombo->currentText(), salEdit->text().toFloat());
        QMessageBox::information(&dialog, "Success", "Staff updated successfully!");
        refreshStaffTable();
        dialog.accept();
    });
    dialog.exec();
}

void AdminWindow::toggleRoomStatus() {
    bool ok;
    int roomNum = QInputDialog::getInt(this, "Toggle Room", "Enter Room Number:", 0, 1, 10000, 1, &ok);
    if (!ok) return;
    
    Room* r = hotel->findRoomByNumber(roomNum);
    if (!r) {
        QMessageBox::warning(this, "Not Found", "Room not found.");
        return;
    }
    
    if (r->isAvailable()) {
        QString guestName = QInputDialog::getText(this, "Book Room", "Room is Available. Enter Guest Username to force book:", QLineEdit::Normal, "", &ok);
        if (ok && !guestName.trimmed().isEmpty()) {
            hotel->adminToggleRoom(roomNum, guestName);
            QMessageBox::information(this, "Success", "Room forcefully booked.");
            refreshRoomsTable();
        }
    } else {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Free Room", "Room is currently booked by " + r->getBookedBy() + ".\nForcefully free this room?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            hotel->adminToggleRoom(roomNum);
            QMessageBox::information(this, "Success", "Room forcefully freed.");
            refreshRoomsTable();
        }
    }
}

void AdminWindow::forceCheckout() {
    bool ok;
    QString username = QInputDialog::getText(this, "Force Checkout", "Enter Customer Username:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;
    
    if (hotel->forceCheckoutCustomer(username)) {
        QMessageBox::information(this, "Success", "Customer forcefully checked out!");
        refreshCustomersTable();
        updateDashboardStats(); // Refresh main dashboard if visible
    } else {
        QMessageBox::warning(this, "Error", "Failed to checkout. Ensure customer currently has a room.");
    }
}

void AdminWindow::deleteFeedback() {
    bool ok;
    QString username = QInputDialog::getText(this, "Delete Feedback", "Enter Username of Feedback to Delete:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;
    
    if (hotel->deleteFeedback(username)) {
        QMessageBox::information(this, "Success", "Feedback deleted!");
        refreshFeedbackTable();
    } else {
        QMessageBox::warning(this, "Error", "Feedback not found.");
    }
}

void AdminWindow::markCleaned() {
    bool ok;
    int roomNum = QInputDialog::getInt(this, "Mark Room Cleaned", "Enter Room Number:", 0, 1, 10000, 1, &ok);
    if (!ok) return;
    
    if (hotel->markRoomCleaned(roomNum)) {
        QMessageBox::information(this, "Success", "Room marked as cleaned.");
        refreshHousekeepingTable();
        refreshRoomsTable(); // Clear dirty status internally
    } else {
        QMessageBox::warning(this, "Error", "Failed. Ensure room exists and needs cleaning.");
    }
}

void AdminWindow::refreshFeedbackTable() {
    QString data = hotel->getFeedback();
    QStringList lines = data.split("\n", Qt::SkipEmptyParts);
    feedbackTable->setRowCount(lines.size());
    for (int i = 0; i < lines.size(); ++i) {
        QStringList fields = lines[i].split(" | ");
        if (fields.size() >= 3) {
            feedbackTable->setItem(i, 0, new QTableWidgetItem(fields[0]));
            feedbackTable->setItem(i, 1, new QTableWidgetItem(fields[1]));
            feedbackTable->setItem(i, 2, new QTableWidgetItem(fields[2]));
        }
    }
}

void AdminWindow::refreshHousekeepingTable() {
    QString data = hotel->getRoomsNeedingCleaning();
    QStringList lines = data.split("\n", Qt::SkipEmptyParts);
    housekeepingTable->setRowCount(lines.size());
    for (int i = 0; i < lines.size(); ++i) {
        QStringList fields = lines[i].split(" | ");
        if (fields.size() >= 2) {
            housekeepingTable->setItem(i, 0, new QTableWidgetItem(fields[0]));
            housekeepingTable->setItem(i, 1, new QTableWidgetItem(fields[1].trimmed()));
        }
    }
}
