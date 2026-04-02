#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include "hotelsystem.h"
#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QStackedWidget>
#include <QTableWidget>
#include <QLabel>

class AdminWindow : public QDialog {
  Q_OBJECT
  HotelSystem *hotel;

  QStackedWidget *stackedWidget;
  QWidget *dashboardPage;
  QWidget *staffPage;
  QWidget *roomsPage;
  QWidget *customersPage;
  QWidget *feedbackPage;
  QWidget *housekeepingPage;

  QTableWidget *staffTable;
  QTableWidget *roomsTable;
  QTableWidget *customersTable;
  QTableWidget *feedbackTable;
  QTableWidget *housekeepingTable;
  QPushButton *viewCustomersButton;
  QPushButton *editCustomerButton;
  QPushButton *viewStaffButton;
  QPushButton *addStaffButton;
  QPushButton *editStaffButton;
  QPushButton *viewRoomsButton;
  QPushButton *addRoomButton;
  QPushButton *toggleRoomButton;
  QPushButton *viewFeedbackMainButton;
  QPushButton *viewHousekeepingMainButton;
  QPushButton *deleteFeedbackButton;
  QPushButton *markCleanedButton;
  QPushButton *forceCheckoutButton;
  QPushButton *logoutButton;

  // Stats Labels
  QLabel *totalGuestsLabel;
  QLabel *totalStaffLabel;
  QLabel *totalRoomsLabel;
  QLabel *bookedRoomsLabel;
  QLabel *earningsLabel;

public:
  AdminWindow(HotelSystem *hotel, QWidget *parent = nullptr);

private:
  void animatePageChange(int index);

private slots:
  void showDashboard();
  void showCustomers();
  void showStaff();
  void showRooms();
  void showFeedback();
  void showHousekeeping();

  void addStaff();
  void editStaff();
  void addRoom();
  void toggleRoomStatus();
  void editCustomer();
  void forceCheckout();
  void deleteFeedback();
  void markCleaned();
  
  void updateDashboardStats();
  void refreshStaffTable();
  void refreshRoomsTable();
  void refreshCustomersTable();
  void refreshFeedbackTable();
  void refreshHousekeepingTable();
};

#endif
