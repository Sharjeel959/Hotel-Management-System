#include "webinterface.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

WebInterface::WebInterface(HotelSystem *h, MainWindow *mw, QObject *parent)
    : QObject(parent), hotel(h), mainWindow(mw) {}

// ── Auth ─────────────────────────────────────────────────────────────────────

bool WebInterface::attemptLogin(const QString &role, const QString &username, const QString &password) {
    User *u = hotel->login(username, password);
    if (u && u->getRole().trimmed().toLower() == role.trimmed().toLower()) {
        currentUser = username;
        currentRole = role;
        return true;
    }
    return false;
}

bool WebInterface::attemptRegister(const QString &role, const QString &name, const QString &phone,
                                   const QString &username, const QString &password,
                                   const QString &email, const QString &position,
                                   const QString &shift, double salary) {
    bool ok = hotel->registerUser(role, name, phone, username, password, email, position, shift, (float)salary);
    if (ok) { currentUser = username; currentRole = role; }
    return ok;
}

void WebInterface::logout() {
    currentUser = "";
    currentRole = "";
}

QString WebInterface::getCurrentUser() { return currentUser; }
QString WebInterface::getCurrentRole() { return currentRole; }

// ── Admin ─────────────────────────────────────────────────────────────────────

QString WebInterface::getAdminDashboardStats() {
    QString rooms = hotel->getRooms();
    // Count booked vs available by scanning the rooms string
    int total = rooms.count("Room #");
    int booked = rooms.count("BOOKED");
    QJsonObject json;
    json["totalRooms"]    = total;
    json["bookedRooms"]   = booked;
    json["freeRooms"]     = total - booked;
    json["pendingActions"] = 0;
    return QString(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

QString WebInterface::getAllRooms() {
    QJsonObject obj;
    obj["data"] = hotel->getRooms();
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

QString WebInterface::getAllBookings() {
    QJsonObject obj;
    obj["data"] = hotel->getCustomers();
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

QString WebInterface::getAllStaff() {
    QJsonObject obj;
    obj["data"] = hotel->getStaff();
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

bool WebInterface::addRoom(int number, const QString &type, double price) {
    return hotel->addRoom(number, type, (float)price);
}

bool WebInterface::addStaff(const QString &name, const QString &phone,
                            const QString &position, const QString &shift, double salary) {
    return hotel->addStaff(name, phone, position, shift, (float)salary);
}

bool WebInterface::toggleRoomStatus(int roomNumber) {
    return hotel->adminToggleRoom(roomNumber, currentUser);
}

bool WebInterface::updateCustomer(const QString &username, const QString &email, const QString &phone) {
    return hotel->updateCustomer(username, email, phone);
}

bool WebInterface::updateStaff(const QString &username, const QString &position,
                               const QString &shift, double salary) {
    return hotel->updateStaff(username, position, shift, (float)salary);
}

QString WebInterface::getReport() {
    QJsonObject obj;
    obj["data"] = hotel->getReport();
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

// ── Guest ──────────────────────────────────────────────────────────────────────

QString WebInterface::getAvailableRooms() {
    QJsonObject obj;
    obj["data"] = hotel->getAvailableRooms();
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

bool WebInterface::bookRoom(int roomNumber) {
    if (currentUser.isEmpty()) return false;
    return hotel->bookRoom(currentUser, roomNumber);
}

bool WebInterface::checkout() {
    if (currentUser.isEmpty()) return false;
    return hotel->checkout(currentUser);
}

QString WebInterface::getMyPaymentInfo() {
    if (currentUser.isEmpty()) return "{}";
    QJsonObject obj;
    obj["data"] = hotel->getPaymentInfo(currentUser);
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

bool WebInterface::makePayment() {
    if (currentUser.isEmpty()) return false;
    return hotel->makePayment(currentUser);
}

bool WebInterface::submitFeedback(const QString &comment, int rating) {
    if (currentUser.isEmpty()) return false;
    return hotel->addFeedback(currentUser, comment, rating);
}

QString WebInterface::getAllFeedback() {
    QJsonObject obj;
    obj["data"] = hotel->getFeedback();
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

bool WebInterface::requestHousekeeping() {
    if (currentUser.isEmpty()) return false;
    return hotel->requestHousekeeping(currentUser);
}

bool WebInterface::joinLoyalty() {
    if (currentUser.isEmpty()) return false;
    return hotel->joinLoyalty(currentUser);
}

QString WebInterface::getRefundInfo() {
    if (currentUser.isEmpty()) return "{}";
    QJsonObject obj;
    obj["data"] = hotel->getRefundInfo(currentUser);
    return QString(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

bool WebInterface::requestRefund() {
    if (currentUser.isEmpty()) return false;
    return hotel->requestRefund(currentUser);
}
