#include "guestwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QStackedWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>


using namespace std;
using namespace Qt;

GuestWindow::GuestWindow(HotelSystem *hotel, const QString &username,
                         QWidget *parent)
    : QDialog(parent), hotel(hotel), username(username) {
  setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
  setWindowTitle("Guest Dashboard - Grand Horizon");
  resize(1050, 680);
  showMaximized();

  QHBoxLayout *mainLayout = new QHBoxLayout(this);
  mainLayout->setContentsMargins(20, 20, 20, 20);
  mainLayout->setSpacing(20);

  // Sidebar Layout (Left side for actions and inputs)
  QVBoxLayout *sidebarLayout = new QVBoxLayout();
  sidebarLayout->setSpacing(10);

  QLabel *headerLabel = new QLabel("Guest Services", this);
  headerLabel->setStyleSheet(
      "font-size: 22px; font-weight: bold; color: #4A90E2; margin-bottom: 20px;");
  headerLabel->setAlignment(Qt::AlignCenter);

  navRoomsButton = new QPushButton("Room Browser", this);
  navBookingButton = new QPushButton("My Bookings", this);
  navActionsButton = new QPushButton("Services & Feedback", this);
  navProfileButton = new QPushButton("My Profile", this);
  
  navRoomsButton->setProperty("class", "nav");
  navBookingButton->setProperty("class", "nav");
  navActionsButton->setProperty("class", "nav");
  navProfileButton->setProperty("class", "nav");
  
  logoutButton = new QPushButton("Logout / Back to Main", this);
  logoutButton->setProperty("class", "logout");

  sidebarLayout->addWidget(headerLabel);
  sidebarLayout->addWidget(navRoomsButton);
  sidebarLayout->addWidget(navBookingButton);
  sidebarLayout->addWidget(navActionsButton);
  sidebarLayout->addWidget(navProfileButton);
  sidebarLayout->addStretch();
  sidebarLayout->addWidget(logoutButton);

  // Main Content Area (Right side)
  stackedWidget = new QStackedWidget(this);

  // 0. Welcome Page
  welcomePage = new QWidget();
  QVBoxLayout *welcomeLayout = new QVBoxLayout(welcomePage);
  welcomeLayout->setAlignment(Qt::AlignCenter);
  
  QLabel *welcomeTitle = new QLabel("Welcome to Grand Horizon, " + username + "!", welcomePage);
  welcomeTitle->setStyleSheet("font-size: 26px; font-weight: bold; color: #4A90E2; margin-bottom: 10px;");
  welcomeTitle->setAlignment(Qt::AlignCenter);
  
  QLabel *welcomeSub = new QLabel("We are honored to have you stay with us. Please explore our luxurious rooms and premium services.", welcomePage);
  welcomeSub->setStyleSheet("font-size: 16px; color: #A0A0A0;");
  welcomeSub->setAlignment(Qt::AlignCenter);
  welcomeSub->setWordWrap(true);
  
  proceedButton = new QPushButton("Proceed to Dashboard", welcomePage);
  proceedButton->setProperty("class", "gold");
  proceedButton->setMinimumHeight(45);
  proceedButton->setMinimumWidth(250);
  
  welcomeLayout->addStretch();
  welcomeLayout->addWidget(welcomeTitle);
  welcomeLayout->addWidget(welcomeSub);
  welcomeLayout->addSpacing(30);
  welcomeLayout->addWidget(proceedButton, 0, Qt::AlignCenter);
  welcomeLayout->addStretch();

  // 1. Rooms Page
  roomsPage = new QWidget();
  QVBoxLayout *roomsLayout = new QVBoxLayout(roomsPage);
  QLabel *roomsTitle = new QLabel("Available & Booked Rooms", roomsPage);
  roomsTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  roomsTable = new QTableWidget(0, 4, roomsPage);
  roomsTable->setHorizontalHeaderLabels({"Room No.", "Type", "Price", "Status"});
  roomsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  roomsLayout->addWidget(roomsTitle);
  roomsLayout->addWidget(roomsTable);

  // 2. Booking Page
  bookingPage = new QWidget();
  QVBoxLayout *bookingLayout = new QVBoxLayout(bookingPage);
  QLabel *bookingTitle = new QLabel("Manage My Reservation", bookingPage);
  bookingTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");

  QGroupBox *bookBox = new QGroupBox("Book a New Room", bookingPage);
  QVBoxLayout *bookBoxLayout = new QVBoxLayout(bookBox);
  roomNumberEdit = new QLineEdit(bookingPage);
  roomNumberEdit->setPlaceholderText("Enter Room Number to Book");
  bookRoomButton = new QPushButton("Execute Booking", bookingPage);
  bookRoomButton->setStyleSheet("background-color: #2E7D32; border-color: #1B5E20;");
  bookBoxLayout->addWidget(roomNumberEdit);
  bookBoxLayout->addWidget(bookRoomButton);

  QGroupBox *checkoutBox = new QGroupBox("Checkout", bookingPage);
  QVBoxLayout *checkoutBoxLayout = new QVBoxLayout(checkoutBox);
  checkoutButton = new QPushButton("Initiate Checkout", bookingPage);
  checkoutBoxLayout->addWidget(checkoutButton);

  bookingLayout->addWidget(bookingTitle);
  bookingLayout->addWidget(bookBox);
  bookingLayout->addWidget(checkoutBox);
  bookingLayout->addStretch();

  // 3. Actions Page
  actionsPage = new QWidget();
  QVBoxLayout *actionsLayout = new QVBoxLayout(actionsPage);
  QLabel *actionsTitle = new QLabel("Guest Services", actionsPage);
  actionsTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");

  QGroupBox *feedbackBox = new QGroupBox("Leave Feedback", actionsPage);
  QVBoxLayout *feedbackLayout = new QVBoxLayout(feedbackBox);
  commentEdit = new QLineEdit(actionsPage);
  commentEdit->setPlaceholderText("Feedback Comment");
  ratingEdit = new QLineEdit(actionsPage);
  ratingEdit->setPlaceholderText("Rating (1-5)");
  addReviewButton = new QPushButton("Submit Feedback", actionsPage);
  feedbackLayout->addWidget(commentEdit);
  feedbackLayout->addWidget(ratingEdit);
  feedbackLayout->addWidget(addReviewButton);

  QGroupBox *servicesBox = new QGroupBox("Hotel Services", actionsPage);
  QVBoxLayout *servicesLayout = new QVBoxLayout(servicesBox);
  viewFeedbackButton = new QPushButton("View Testimonials", actionsPage);
  housekeepingButton = new QPushButton("Request Housekeeping", actionsPage);
  makePaymentButton = new QPushButton("Make Payment (Invoice)", actionsPage);
  requestRefundButton = new QPushButton("Request Refund", actionsPage);
  loyaltyButton = new QPushButton("Join Loyalty Program", actionsPage);
  roomServiceButton = new QPushButton("Order Room Service", actionsPage);
  upgradeRoomButton = new QPushButton("Request Room Upgrade", actionsPage);
  
  servicesLayout->addWidget(viewFeedbackButton);
  servicesLayout->addWidget(housekeepingButton);
  servicesLayout->addWidget(roomServiceButton);
  servicesLayout->addWidget(makePaymentButton);
  servicesLayout->addWidget(requestRefundButton);
  servicesLayout->addWidget(loyaltyButton);
  servicesLayout->addWidget(upgradeRoomButton);

  actionsLayout->addWidget(actionsTitle);
  actionsLayout->addWidget(feedbackBox);
  actionsLayout->addWidget(servicesBox);
  actionsLayout->addStretch();

  // 4. Profile Page
  profilePage = new QWidget();
  QVBoxLayout *profileLayout = new QVBoxLayout(profilePage);
  QLabel *profileTitle = new QLabel("My Profile", profilePage);
  profileTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: #FFFFFF;");
  
  QFormLayout *formLayout = new QFormLayout();
  profileEmailEdit = new QLineEdit(profilePage);
  profilePhoneEdit = new QLineEdit(profilePage);
  loyaltyStatusLabel = new QLabel(profilePage);
  pointsLabel = new QLabel(profilePage);
  
  formLayout->addRow("Email:", profileEmailEdit);
  formLayout->addRow("Phone:", profilePhoneEdit);
  formLayout->addRow("Loyalty Member:", loyaltyStatusLabel);
  formLayout->addRow("Loyalty Points:", pointsLabel);
  
  saveProfileButton = new QPushButton("Save Profile Changes", profilePage);
  
  profileLayout->addWidget(profileTitle);
  profileLayout->addLayout(formLayout);
  profileLayout->addWidget(saveProfileButton);
  profileLayout->addStretch();

  stackedWidget->addWidget(welcomePage);  // Index 0
  stackedWidget->addWidget(roomsPage);    // Index 1
  stackedWidget->addWidget(bookingPage);  // Index 2
  stackedWidget->addWidget(actionsPage);  // Index 3
  stackedWidget->addWidget(profilePage);  // Index 4

  mainLayout->addLayout(sidebarLayout, 1);
  mainLayout->addWidget(stackedWidget, 3);

  connect(proceedButton, &QPushButton::clicked, this, &GuestWindow::showRoomsPage);
  connect(navRoomsButton, &QPushButton::clicked, this, &GuestWindow::showRoomsPage);
  connect(navBookingButton, &QPushButton::clicked, this, &GuestWindow::showBookingPage);
  connect(navActionsButton, &QPushButton::clicked, this, &GuestWindow::showActionsPage);
  connect(navProfileButton, &QPushButton::clicked, this, &GuestWindow::showProfilePage);
  
  connect(bookRoomButton, &QPushButton::clicked, this, &GuestWindow::bookRoom);
  connect(checkoutButton, &QPushButton::clicked, this, &GuestWindow::checkout);
  connect(addReviewButton, &QPushButton::clicked, this, &GuestWindow::addReview);
  connect(viewFeedbackButton, &QPushButton::clicked, this, &GuestWindow::viewFeedback);
  connect(housekeepingButton, &QPushButton::clicked, this, &GuestWindow::requestHousekeeping);
  connect(makePaymentButton, &QPushButton::clicked, this, &GuestWindow::showDetailedInvoice); // changed to invoice
  connect(requestRefundButton, &QPushButton::clicked, this, &GuestWindow::requestRefund);
  connect(loyaltyButton, &QPushButton::clicked, this, &GuestWindow::joinLoyalty);
  connect(roomServiceButton, &QPushButton::clicked, this, &GuestWindow::orderRoomService);
  connect(upgradeRoomButton, &QPushButton::clicked, this, &GuestWindow::requestRoomUpgrade);
  connect(saveProfileButton, &QPushButton::clicked, this, &GuestWindow::updateProfile);
  
  connect(logoutButton, &QPushButton::clicked, this, &QDialog::accept);
  
  showWelcomePage(); // default visible
  loadProfileData();
}

void GuestWindow::animatePageChange(int index) {
    if (stackedWidget->currentIndex() == index) return;
    
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(stackedWidget->widget(index));
    stackedWidget->widget(index)->setGraphicsEffect(effect);
    
    stackedWidget->setCurrentIndex(index);
    
    QPropertyAnimation *anim = new QPropertyAnimation(effect, "opacity");
    anim->setDuration(300); // 300 ms fade
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void GuestWindow::showWelcomePage() { animatePageChange(0); }
void GuestWindow::showRoomsPage() { animatePageChange(1); refreshRoomsTable(); }
void GuestWindow::showBookingPage() { animatePageChange(2); }
void GuestWindow::showActionsPage() { animatePageChange(3); }
void GuestWindow::showProfilePage() { animatePageChange(4); loadProfileData(); }

void GuestWindow::loadProfileData() {
    Guest* g = hotel->findGuestByUsername(username);
    if (g) {
        profileEmailEdit->setText(g->getEmail());
        profilePhoneEdit->setText(g->getPhone());
        loyaltyStatusLabel->setText(g->isLoyal() ? "Yes" : "No");
        pointsLabel->setText(QString::number(g->getPoints()));
    }
}

void GuestWindow::updateProfile() {
    if (hotel->updateCustomer(username, profileEmailEdit->text(), profilePhoneEdit->text())) {
        QMessageBox::information(this, "Success", "Profile updated successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Failed to update profile.");
    }
}

void GuestWindow::refreshRoomsTable() {
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
              QTableWidgetItem *statusItem = new QTableWidgetItem("Booked");
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

void GuestWindow::bookRoom() {
  bool ok;
  int roomNum = roomNumberEdit->text().toInt(&ok);
  if (!ok || roomNum <= 0) {
    QMessageBox::warning(this, "Error", "Invalid room number.");
    return;
  }
  if (hotel->bookRoom(username, roomNum)) {
    QMessageBox::information(this, "Success",
                             "Room booked successfully! Please make payment.");
    // No direct textedit layout
  } else {
    QMessageBox::warning(this, "Error",
                         "Room not available or already booked.");
  }
}

void GuestWindow::checkout() {
  if (hotel->checkout(username)) {
    QMessageBox::information(this, "Success", "Checked out successfully!");
  } else {
    QMessageBox::warning(this, "Error", "No room booked.");
  }
}

void GuestWindow::addReview() {
  bool ok;
  int rating = ratingEdit->text().toInt(&ok);
  if (!ok || rating < 1 || rating > 5) {
    QMessageBox::warning(this, "Error", "Rating must be between 1 and 5.");
    return;
  }
  if (hotel->addFeedback(username, commentEdit->text(), rating)) {
    QMessageBox::information(this, "Success", "Feedback submitted!");
    commentEdit->clear();
    ratingEdit->clear();
  } else {
    QMessageBox::warning(this, "Error", "Failed to submit feedback.");
  }
}

void GuestWindow::viewFeedback() { 
  QMessageBox::information(this, "Testimonials", hotel->getFeedback());
}

void GuestWindow::requestHousekeeping() {
  if (hotel->requestHousekeeping(username)) {
    QMessageBox::information(this, "Success", "Housekeeping requested!");
  } else {
    QMessageBox::warning(this, "Error", "No room booked.");
  }
}

void GuestWindow::showDetailedInvoice() {
    Guest *guest = hotel->findGuestByUsername(username);
    if (!guest || guest->getRoomNumber() == 0) {
        QMessageBox::warning(this, "Error", "You do not have any active bookings to pay for.");
        return;
    }
    
    Room *room = hotel->findRoomByNumber(guest->getRoomNumber());
    if (!room) return;
    
    QDialog dialog(this);
    dialog.setWindowTitle("Detailed Invoice");
    dialog.resize(300, 250);
    QVBoxLayout layout(&dialog);
    
    float originalPrice = room->getPrice();
    float discount = guest->isLoyal() ? (originalPrice * guest->getDiscount()) : 0.0f;
    float finalTotal = originalPrice - discount;
    
    QLabel *title = new QLabel("<b>Invoice Details</b>");
    QLabel *roomLbl = new QLabel("Room: " + QString::number(room->getNumber()) + " (" + room->getType() + ")");
    QLabel *priceLbl = new QLabel("Base Price: $" + QString::number(originalPrice, 'f', 2));
    QLabel *discLbl = new QLabel("Loyalty Discount: -$" + QString::number(discount, 'f', 2));
    QLabel *totalLbl = new QLabel("<b>Total Due: $" + QString::number(finalTotal, 'f', 2) + "</b>");
    
    layout.addWidget(title);
    layout.addWidget(roomLbl);
    layout.addWidget(priceLbl);
    layout.addWidget(discLbl);
    layout.addWidget(totalLbl);
    
    QHBoxLayout btns;
    QPushButton payBtn("Confirm Payment");
    QPushButton cancelBtn("Cancel");
    btns.addWidget(&cancelBtn);
    btns.addWidget(&payBtn);
    layout.addLayout(&btns);
    
    connect(&cancelBtn, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&payBtn, &QPushButton::clicked, [&]() {
        hotel->makePayment(username);
        QMessageBox::information(&dialog, "Success", "Payment successfully processed! Thank you.");
        dialog.accept();
    });
    
    dialog.exec();
}

void GuestWindow::makePayment() {
  QString info = hotel->getPaymentInfo(username);
  QMessageBox::StandardButton reply =
      QMessageBox::question(this, "Payment", info + "\nConfirm payment?",
                            QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::Yes && hotel->makePayment(username)) {
    QMessageBox::information(this, "Success", "Payment completed!");
  }
}

void GuestWindow::orderRoomService() {
    Guest *guest = hotel->findGuestByUsername(username);
    if (guest && guest->getRoomNumber() != 0) {
        QMessageBox::information(this, "Room Service", "Room service order received! It will be delivered to Room " + QString::number(guest->getRoomNumber()) + " shortly.");
    } else {
        QMessageBox::warning(this, "Error", "You must book a room first to order room service.");
    }
}

void GuestWindow::requestRoomUpgrade() {
    Guest *guest = hotel->findGuestByUsername(username);
    if (!guest || guest->getRoomNumber() == 0) {
        QMessageBox::warning(this, "Error", "You must have an active booking to request an upgrade.");
        return;
    }
    
    QMessageBox::information(this, "Upgrade Request", "Your room upgrade request has been successfully submitted to the front desk. They will contact you shortly regarding availability.");
}

void GuestWindow::requestRefund() {
  QString info = hotel->getRefundInfo(username);
  QMessageBox::StandardButton reply =
      QMessageBox::question(this, "Refund", info + "\nConfirm refund request?",
                            QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::Yes && hotel->requestRefund(username)) {
    QMessageBox::information(this, "Success", "Refund request submitted!");
  }
}

void GuestWindow::joinLoyalty() {
  if (hotel->joinLoyalty(username)) {
    QMessageBox::information(
        this, "Success", "You are now a loyal member! 40% discount applied.");
  } else {
    QMessageBox::warning(this, "Error", "Already a member or no guest record.");
  }
}
