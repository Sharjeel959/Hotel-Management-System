#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H

#include "hotelsystem.h"
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QStackedWidget>
#include <QTableWidget>
#include <QLabel>
#include <QFormLayout>

class GuestWindow : public QDialog {
  Q_OBJECT

public:
  GuestWindow(HotelSystem *hotel, const QString &username,
              QWidget *parent = nullptr);

private:
  void animatePageChange(int index);

private slots:
  void showWelcomePage();
  void showRoomsPage();
  void showBookingPage();
  void showActionsPage();
  void showProfilePage();

  void bookRoom();
  void checkout();
  void addReview();
  void viewFeedback();
  void requestHousekeeping();
  void makePayment();
  void requestRefund();
  void joinLoyalty();
  
  void updateProfile();
  void orderRoomService();
  void requestRoomUpgrade();
  
  void loadProfileData();
  void showDetailedInvoice();
  
  void refreshRoomsTable();

private:
  HotelSystem *hotel;
  QString username;

  QStackedWidget *stackedWidget;
  QWidget *welcomePage;
  QWidget *roomsPage;
  QWidget *bookingPage;
  QWidget *actionsPage;
  QWidget *profilePage;
  
  QTableWidget *roomsTable;

  QPushButton *proceedButton;
  QPushButton *navRoomsButton;
  QPushButton *navBookingButton;
  QPushButton *navActionsButton;
  QPushButton *navProfileButton;

  QPushButton *bookRoomButton;
  QPushButton *checkoutButton;
  QPushButton *addReviewButton;
  QPushButton *viewFeedbackButton;
  QPushButton *housekeepingButton;
  QPushButton *makePaymentButton;
  QPushButton *requestRefundButton;
  QPushButton *loyaltyButton;
  QPushButton *roomServiceButton;
  QPushButton *upgradeRoomButton;
  QPushButton *saveProfileButton;
  QPushButton *logoutButton;

  QLineEdit *roomNumberEdit;
  QLineEdit *commentEdit;
  QLineEdit *ratingEdit;

  // Profile fields
  QLineEdit *profileEmailEdit;
  QLineEdit *profilePhoneEdit;
  QLabel *loyaltyStatusLabel;
  QLabel *pointsLabel;
};

#endif // GUESTWINDOW_H
