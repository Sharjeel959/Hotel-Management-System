#include "hotelsystem.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

using namespace Qt;

HotelSystem::HotelSystem()
    : userCount(0), roomCount(0), guestCount(0), staffCount(0),
      feedbackCount(0) {
  loadUsersFromFile();
  loadRoomsFromFile();
  loadStaffFromFile();
  loadGuestsFromFile();
  loadFeedbackFromFile();

  if (roomCount == 0 && staffCount == 0) {
      addRoom(101, "Presidential Suite", 1200.0);
      addRoom(102, "Ocean View Double", 800.0);
      addRoom(103, "Executive Single", 550.0);
      addRoom(104, "Standard Single", 250.0);
      addRoom(105, "Standard Double", 350.0);
      
      addStaff("Sarah Jenkins", "+15550101", "General Manager", "morning", 85000.0);
      addStaff("Marcus Vance", "+15550102", "Head Concierge", "evening", 45000.0);
      addStaff("Elena Rossi", "+15550103", "Receptionist", "night", 32000.0);
  }
}

void HotelSystem::saveUsersToFile() {
  QFile file("users.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < userCount; i++) {
      out << users[i].getName() << "|" << users[i].getPhone() << "|"
          << users[i].getUsername() << "|" << users[i].getPassword() << "|"
          << users[i].getRole() << "\n";
    }
    file.close();
  }
}

void HotelSystem::loadUsersFromFile() {
  QFile file("users.txt");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    while (!in.atEnd() && userCount < maximumUsers) {
      QString line = in.readLine();
      QStringList fields = line.split("|");
      if (fields.size() == 5) {
        users[userCount++] =
            User(fields[0].trimmed(), fields[1].trimmed(), fields[2].trimmed(), fields[3].trimmed(), fields[4].trimmed());
      }
    }
    file.close();
  }
}

void HotelSystem::saveRoomsToFile() {
  QFile file("rooms.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < roomCount; i++) {
      out << rooms[i].getNumber() << "|" << rooms[i].getType() << "|"
          << rooms[i].getPrice() << "|" << rooms[i].isAvailable() << "|"
          << rooms[i].cleaningRequired() << "|" << rooms[i].getBookedBy()
          << "\n";
    }
    file.close();
  }
}

void HotelSystem::loadRoomsFromFile() {
  QFile file("rooms.txt");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    while (!in.atEnd() && roomCount < maximumRooms) {
      QString line = in.readLine();
      QStringList fields = line.split("|");
      if (fields.size() == 6) {
        rooms[roomCount] =
            Room(fields[0].toInt(), fields[1], fields[2].toFloat());
        rooms[roomCount].bookRoom(fields[5]); // Handle bookedBy
        rooms[roomCount].markCleaned();       // Reset cleaning if needed
        roomCount++;
      }
    }
    file.close();
  }
}

void HotelSystem::saveStaffToFile() {
  QFile file("staff.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < staffCount; i++) {
      out << staff[i].getName() << "|" << staff[i].getPhone() << "|"
          << staff[i].getPosition() << "|" << staff[i].getShift() << "|"
          << staff[i].getSalary() << "\n";
    }
    file.close();
  }
}

void HotelSystem::loadStaffFromFile() {
  QFile file("staff.txt");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    while (!in.atEnd() && staffCount < maximumStaff) {
      QString line = in.readLine();
      QStringList fields = line.split("|");
      if (fields.size() == 5) {
        staff[staffCount++] = Staff(fields[0], fields[1], fields[2], fields[3],
                                    fields[4].toFloat());
      }
    }
    file.close();
  }
}

void HotelSystem::saveGuestsToFile() {
  QFile file("guests.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < guestCount; i++) {
      out << guests[i].getName() << "|" << guests[i].getPhone() << "|"
          << guests[i].getEmail() << "|" << guests[i].getRoomNumber() << "|"
          << guests[i].isLoyal() << "|" << guests[i].getPoints() << "|"
          << guests[i].getDiscount() << "\n";
    }
    file.close();
  }
}

void HotelSystem::loadGuestsFromFile() {
  QFile file("guests.txt");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    while (!in.atEnd() && guestCount < maximumGuests) {
      QString line = in.readLine();
      QStringList fields = line.split("|");
      if (fields.size() == 7) {
        guests[guestCount] = Guest(fields[0], fields[1], fields[2]);
        guests[guestCount].setRoomNumber(fields[3].toInt());
        guests[guestCount]
            .makeLoyalMember(); // Adjust based on file data if needed
        guestCount++;
      }
    }
    file.close();
  }
}

void HotelSystem::saveFeedbackToFile() {
  QFile file("feedback.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = 0; i < feedbackCount; i++) {
      out << feedbacks[i].getUsername() << "|" << feedbacks[i].getComment()
          << "|" << feedbacks[i].getRating() << "\n";
    }
    file.close();
  }
}

void HotelSystem::loadFeedbackFromFile() {
  QFile file("feedback.txt");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    while (!in.atEnd() && feedbackCount < maximumGuests) {
      QString line = in.readLine();
      QStringList fields = line.split("|");
      if (fields.size() == 3) {
        feedbacks[feedbackCount++] =
            Feedback(fields[0], fields[1], fields[2].toInt());
      }
    }
    file.close();
  }
}

void HotelSystem::cleanUpGuestData() {
  for (int i = 0; i < guestCount; i++) {
    guests[i].setRoomNumber(0);
  }
}

User *HotelSystem::findUserByUsername(const QString &username) {
  for (int i = 0; i < userCount; i++) {
    if (users[i].getUsername() == username) {
      return &users[i];
    }
  }
  return nullptr;
}

Guest *HotelSystem::findGuestByUsername(const QString &username) {
  for (int i = 0; i < guestCount; i++) {
    if (guests[i].getName() ==
        username) { // Adjust to match username if stored differently
      return &guests[i];
    }
  }
  return nullptr;
}

Staff *HotelSystem::findStaffByUsername(const QString &username) {
  for (int i = 0; i < staffCount; i++) {
    if (staff[i].getName() ==
        username) { // Adjust to match username if stored differently
      return &staff[i];
    }
  }
  return nullptr;
}

Room *HotelSystem::findRoomByNumber(int number) {
  for (int i = 0; i < roomCount; i++) {
    if (rooms[i].getNumber() == number) {
      return &rooms[i];
    }
  }
  return nullptr;
}

bool HotelSystem::registerUser(const QString &role, const QString &name,
                               const QString &phone, const QString &username,
                               const QString &password, const QString &email,
                               const QString &position, const QString &shift,
                               float salary) {
  if (userCount >= maximumUsers)
    return false;
  if (findUserByUsername(username))
    return false;

  if (role == "guest") {
    guests[guestCount++] = Guest(name, phone, email);
    users[userCount++] = User(name, phone, username, password, role);
  } else if (role == "staff") {
    staff[staffCount++] = Staff(name, phone, position, shift, salary);
    users[userCount++] = User(name, phone, username, password, role);
  } else if (role == "admin") {
    users[userCount++] = User(name, phone, username, password, role);
  }
  saveUsersToFile();
  emit registrationSuccess();
  return true;
}

User *HotelSystem::login(const QString &username, const QString &password) {
  User *user = findUserByUsername(username);
  if (user && user->authenticate(password)) {
    qDebug() << "Login successful for:" << username;
    emit loginSuccess(user);
    return user;
  }
  qDebug() << "Login failed for:" << username;
  emit loginFailed();
  return nullptr;
}

QString HotelSystem::getCustomers() {
  QString result;
  for (int i = 0; i < guestCount; i++) {
    result += guests[i].getName() + " | " + guests[i].getPhone() + " | " +
              guests[i].getEmail() + "\n";
  }
  return result;
}

QString HotelSystem::getStaff() {
  QString result;
  for (int i = 0; i < staffCount; i++) {
    result += staff[i].getName() + " | " + staff[i].getPosition() + " | " +
              QString::number(staff[i].getSalary()) + "\n";
  }
  return result;
}

bool HotelSystem::addStaff(const QString &name, const QString &phone,
                           const QString &position, const QString &shift,
                           float salary) {
  if (staffCount >= maximumStaff)
    return false;
  staff[staffCount++] = Staff(name, phone, position, shift, salary);
  saveStaffToFile();
  return true;
}

QString HotelSystem::getRooms() {
  QString result;
  for (int i = 0; i < roomCount; i++) {
    result += QString::number(rooms[i].getNumber()) + " | " +
              rooms[i].getType() + " | " +
              QString::number(rooms[i].getPrice()) + "\n";
  }
  return result;
}

bool HotelSystem::addRoom(int number, const QString &type, float price) {
  if (roomCount >= maximumRooms || findRoomByNumber(number))
    return false;
  rooms[roomCount++] = Room(number, type, price);
  saveRoomsToFile();
  return true;
}

bool HotelSystem::adminToggleRoom(int roomNumber, const QString& forUser) {
  Room* room = findRoomByNumber(roomNumber);
  if (!room) return false;

  if (room->isAvailable()) {
    if (forUser.isEmpty()) return false;
    room->bookRoom(forUser);
    Guest* g = findGuestByUsername(forUser);
    if (g) g->setRoomNumber(roomNumber);
  } else {
    Guest* g = findGuestByUsername(room->getBookedBy());
    if (g) g->setRoomNumber(0);
    room->freeRoom();
  }
  saveRoomsToFile();
  saveGuestsToFile();
  return true;
}

bool HotelSystem::updateCustomer(const QString& username, const QString& newEmail, const QString& newPhone) {
  Guest* guest = findGuestByUsername(username);
  if (!guest) return false;
  
  guest->setEmail(newEmail);
  guest->setPhone(newPhone);
  
  User* user = findUserByUsername(username);
  if (user) user->setPhone(newPhone);
  
  saveGuestsToFile();
  saveUsersToFile();
  return true;
}

bool HotelSystem::updateStaff(const QString& username, const QString& newPosition, const QString& newShift, float newSalary) {
  Staff* staffMem = findStaffByUsername(username);
  if (!staffMem) return false;
  
  staffMem->setPosition(newPosition);
  staffMem->setShift(newShift);
  staffMem->setSalary(newSalary);
  
  saveStaffToFile();
  return true;
}

QString HotelSystem::getReport() {
  return getCustomers() + "\n" + getStaff() + "\n" + getRooms();
}

QString HotelSystem::getStaffInfo(const QString &username) {
  Staff *s = findStaffByUsername(username);
  return s ? s->getName() + " | " + s->getPosition() : "Staff not found";
}

QString HotelSystem::getAvailableRooms() {
  QString result;
  for (int i = 0; i < roomCount; i++) {
    if (rooms[i].isAvailable()) {
      result += QString::number(rooms[i].getNumber()) + " | " +
                rooms[i].getType() + " | " +
                QString::number(rooms[i].getPrice()) + "\n";
    }
  }
  return result;
}

bool HotelSystem::bookRoom(const QString &username, int roomNum) {
  Room *room = findRoomByNumber(roomNum);
  if (room && room->isAvailable()) {
    room->bookRoom(username);
    Guest *guest = findGuestByUsername(username);
    if (guest)
      guest->setRoomNumber(roomNum);
    saveRoomsToFile();
    saveGuestsToFile();
    return true;
  }
  return false;
}

bool HotelSystem::checkout(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && guest->getRoomNumber() != 0) {
    Room *room = findRoomByNumber(guest->getRoomNumber());
    if (room) {
      room->freeRoom();
      guest->setRoomNumber(0);
      saveRoomsToFile();
      saveGuestsToFile();
      return true;
    }
  }
  return false;
}

bool HotelSystem::addFeedback(const QString &username, const QString &comment,
                              int rating) {
  if (feedbackCount >= maximumGuests || rating < 1 || rating > 5)
    return false;
  feedbacks[feedbackCount++] = Feedback(username, comment, rating);
  saveFeedbackToFile();
  return true;
}

QString HotelSystem::getFeedback() {
  QString result;
  for (int i = 0; i < feedbackCount; i++) {
    result += feedbacks[i].getUsername() + " | " + feedbacks[i].getComment() +
              " | " + QString::number(feedbacks[i].getRating()) + "\n";
  }
  return result;
}

bool HotelSystem::requestHousekeeping(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && guest->getRoomNumber() != 0) {
    Room *room = findRoomByNumber(guest->getRoomNumber());
    if (room) {
      room->markCleaned();
      saveRoomsToFile();
      return true;
    }
  }
  return false;
}

QString HotelSystem::getPaymentInfo(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && guest->getRoomNumber() != 0) {
    Room *room = findRoomByNumber(guest->getRoomNumber());
    return room ? QString("Pay %1 for room %2")
                      .arg(room->getPrice())
                      .arg(room->getNumber())
                : "No room booked";
  }
  return "No room booked";
}

bool HotelSystem::makePayment(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && guest->getRoomNumber() != 0) {
    // Simulate payment (no actual payment processing)
    saveGuestsToFile();
    return true;
  }
  return false;
}

QString HotelSystem::getRefundInfo(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && guest->getRoomNumber() != 0) {
    Room *room = findRoomByNumber(guest->getRoomNumber());
    return room ? QString("Request refund for room %1").arg(room->getNumber())
                : "No room booked";
  }
  return "No room booked";
}

bool HotelSystem::requestRefund(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && guest->getRoomNumber() != 0) {
    // Simulate refund request
    saveGuestsToFile();
    return true;
  }
  return false;
}

bool HotelSystem::joinLoyalty(const QString &username) {
  Guest *guest = findGuestByUsername(username);
  if (guest && !guest->isLoyal()) {
    guest->makeLoyalMember();
    saveGuestsToFile();
    return true;
  }
  return false;
}

int HotelSystem::getTotalGuests() const { return guestCount; }
int HotelSystem::getTotalStaff() const { return staffCount; }
int HotelSystem::getTotalRooms() const { return roomCount; }

int HotelSystem::getBookedRoomsCount() const {
    int count = 0;
    for (int i = 0; i < roomCount; ++i) {
        if (!rooms[i].isAvailable()) count++;
    }
    return count;
}

float HotelSystem::calculateEstimatedEarnings() const {
    float total = 0.0f;
    for (int i = 0; i < roomCount; ++i) {
        if (!rooms[i].isAvailable()) {
            total += rooms[i].getPrice();
        }
    }
    return total;
}

QString HotelSystem::getRoomsNeedingCleaning() {
    QString result;
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i].cleaningRequired()) {
            result += QString::number(rooms[i].getNumber()) + " | " + rooms[i].getType() + "\n";
        }
    }
    return result;
}

bool HotelSystem::markRoomCleaned(int roomNumber) {
    Room *room = findRoomByNumber(roomNumber);
    if (room && room->cleaningRequired()) {
        room->markCleaned();
        saveRoomsToFile();
        return true;
    }
    return false;
}

bool HotelSystem::deleteFeedback(const QString& username) {
    for (int i = 0; i < feedbackCount; ++i) {
        if (feedbacks[i].getUsername() == username) {
            for (int j = i; j < feedbackCount - 1; ++j) {
                feedbacks[j] = feedbacks[j + 1];
            }
            feedbackCount--;
            saveFeedbackToFile();
            return true;
        }
    }
    return false;
}

bool HotelSystem::forceCheckoutCustomer(const QString& username) {
    return checkout(username);
}
