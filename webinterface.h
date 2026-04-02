#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H

#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "hotelsystem.h"

class MainWindow;

class WebInterface : public QObject {
  Q_OBJECT
  HotelSystem *hotel;
  MainWindow *mainWindow;
  QString currentUser;
  QString currentRole;

public:
  explicit WebInterface(HotelSystem *h, MainWindow *mw, QObject *parent = nullptr);

  // ── Auth ──────────────────────────────────────────────────────────────────
  Q_INVOKABLE bool   attemptLogin(const QString &role, const QString &username, const QString &password);
  Q_INVOKABLE bool   attemptRegister(const QString &role, const QString &name, const QString &phone,
                                     const QString &username, const QString &password,
                                     const QString &email, const QString &position,
                                     const QString &shift, double salary);
  Q_INVOKABLE void   logout();
  Q_INVOKABLE QString getCurrentUser();
  Q_INVOKABLE QString getCurrentRole();

  // ── Admin ─────────────────────────────────────────────────────────────────
  Q_INVOKABLE QString getAdminDashboardStats();
  Q_INVOKABLE QString getAllRooms();
  Q_INVOKABLE QString getAllBookings();
  Q_INVOKABLE QString getAllStaff();
  Q_INVOKABLE bool   addRoom(int number, const QString &type, double price);
  Q_INVOKABLE bool   addStaff(const QString &name, const QString &phone,
                              const QString &position, const QString &shift, double salary);
  Q_INVOKABLE bool   toggleRoomStatus(int roomNumber);
  Q_INVOKABLE bool   updateCustomer(const QString &username, const QString &email, const QString &phone);
  Q_INVOKABLE bool   updateStaff(const QString &username, const QString &position,
                                 const QString &shift, double salary);
  Q_INVOKABLE QString getReport();

  // ── Guest ─────────────────────────────────────────────────────────────────
  Q_INVOKABLE QString getAvailableRooms();
  Q_INVOKABLE bool   bookRoom(int roomNumber);
  Q_INVOKABLE bool   checkout();
  Q_INVOKABLE QString getMyPaymentInfo();
  Q_INVOKABLE bool   makePayment();
  Q_INVOKABLE bool   submitFeedback(const QString &comment, int rating);
  Q_INVOKABLE QString getAllFeedback();
  Q_INVOKABLE bool   requestHousekeeping();
  Q_INVOKABLE bool   joinLoyalty();
  Q_INVOKABLE QString getRefundInfo();
  Q_INVOKABLE bool   requestRefund();
};

#endif // WEBINTERFACE_H
