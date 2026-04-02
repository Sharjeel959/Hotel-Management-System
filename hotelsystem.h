#ifndef HOTELSYSTEM_H
#define HOTELSYSTEM_H

#include <QString>
#include <QObject>
#include <fstream>

using namespace Qt;

const int maximumUsers = 100;
const int maximumRooms = 50;
const int maximumGuests = 200;
const int maximumStaff = 50;

class Person {
protected:
    QString name;
    QString phone;
public:
    Person() {}
    Person(const QString& n, const QString& p) : name(n), phone(p) {}
    QString getName() const { return name; }
    QString getPhone() const { return phone; }
    void setPhone(const QString& p) { phone = p; }
    virtual QString getRole() const = 0;
};

class User : public Person {
    QString username;
    QString password;
    QString role;
public:
    User() {}
    User(const QString& n, const QString& p, const QString& u, const QString& pass, const QString& r)
        : Person(n, p), username(u), password(pass), role(r) {}
    bool authenticate(const QString& pass) const { return pass == password; }
    QString getUsername() const { return username; }
    QString getPassword() const { return password; }
    QString getRole() const override { return role; }
};

class Room {
    int number;
    QString type;
    float price;
    bool available;
    bool needsCleaning;
    QString bookedBy;
public:
    Room() : number(0), type(""), price(0.0f), available(true), needsCleaning(false), bookedBy("") {}
    Room(int num, const QString& t, float p)
        : number(num), type(t), price(p), available(true), needsCleaning(false), bookedBy("") {}
    void bookRoom(const QString& username) {
        available = false;
        needsCleaning = true;
        bookedBy = username;
    }
    void freeRoom() {
        available = true;
        needsCleaning = true;
        bookedBy = "";
    }
    bool isAvailable() const { return available; }
    bool cleaningRequired() const { return needsCleaning; }
    void markCleaned() { needsCleaning = false; }
    QString getBookedBy() const { return bookedBy; }
    int getNumber() const { return number; }
    QString getType() const { return type; }
    float getPrice() const { return price; }
};

class Staff : public Person {
    QString position;
    QString shift;
    float salary;
public:
    Staff() : salary(0) {}
    Staff(const QString& n, const QString& p, const QString& pos, const QString& s, float sal)
        : Person(n, p), position(pos), shift(s), salary(sal > 0 ? sal : 0) {}
    QString getPosition() const { return position; }
    QString getShift() const { return shift; }
    float getSalary() const { return salary; }
    void setPosition(const QString& pos) { position = pos; }
    void setShift(const QString& s) { shift = s; }
    void setSalary(float sal) { salary = sal; }
    QString getRole() const override { return "staff"; }
};

class Guest : public Person {
    QString email;
    int loyaltyPoints;
    int roomNumber;
    bool isLoyalMember;
    float discountRate;
public:
    Guest() : loyaltyPoints(0), roomNumber(0), isLoyalMember(false), discountRate(0.0f) {}
    Guest(const QString& n, const QString& p, const QString& e)
        : Person(n, p), email(e), loyaltyPoints(0), roomNumber(0), isLoyalMember(false), discountRate(0.0f) {}
    void makeLoyalMember() {
        isLoyalMember = true;
        discountRate = 0.4f;
    }
    bool isLoyal() const { return isLoyalMember; }
    float getDiscount() const { return discountRate; }
    void addPoints(int pts) { loyaltyPoints += pts; }
    int getPoints() const { return loyaltyPoints; }
    QString getEmail() const { return email; }
    void setEmail(const QString& e) { email = e; }
    void setRoomNumber(int rn) { roomNumber = rn; }
    int getRoomNumber() const { return roomNumber; }
    QString getRole() const override { return "guest"; }
};

class Feedback {
    QString username;
    QString comments;
    int rating;
public:
    Feedback() : rating(0) {}
    Feedback(const QString& u, const QString& c, int r) : username(u), comments(c), rating(r) {}
    QString getUsername() const { return username; }
    QString getComment() const { return comments; }
    int getRating() const { return rating; }
};

class HotelSystem : public QObject {
    Q_OBJECT
    User users[maximumUsers];
    int userCount;
    Room rooms[maximumRooms];
    int roomCount;
    Guest guests[maximumGuests];
    int guestCount;
    Staff staff[maximumStaff];
    int staffCount;
    Feedback feedbacks[maximumGuests];
    int feedbackCount;

    void saveUsersToFile();
    void loadUsersFromFile();
    void saveRoomsToFile();
    void loadRoomsFromFile();
    void saveStaffToFile();
    void loadStaffFromFile();
    void saveGuestsToFile();
    void loadGuestsFromFile();
    void saveFeedbackToFile();
    void loadFeedbackFromFile();
    void cleanUpGuestData();
    User* findUserByUsername(const QString& username);

public:
    Guest* findGuestByUsername(const QString& username);
    Staff* findStaffByUsername(const QString& username);
    Room* findRoomByNumber(int number);
    HotelSystem();
    bool registerUser(const QString& role, const QString& name, const QString& phone, const QString& username,
                      const QString& password, const QString& email = "", const QString& position = "",
                      const QString& shift = "", float salary = 0.0f);
    User* login(const QString& username, const QString& password);
    QString getCustomers();
    QString getStaff();
    bool addStaff(const QString& name, const QString& phone, const QString& position, const QString& shift, float salary);
    QString getRooms();
    bool addRoom(int number, const QString& type, float price);
    bool adminToggleRoom(int roomNumber, const QString& forUser = "");
    bool updateCustomer(const QString& username, const QString& newEmail, const QString& newPhone);
    bool updateStaff(const QString& username, const QString& newPosition, const QString& newShift, float newSalary);
    QString getReport();
    QString getStaffInfo(const QString& username);
    QString getAvailableRooms();
    bool bookRoom(const QString& username, int roomNum);
    bool checkout(const QString& username);
    bool addFeedback(const QString& username, const QString& comment, int rating);
    QString getFeedback();
    bool requestHousekeeping(const QString& username);
    QString getPaymentInfo(const QString& username);
    bool makePayment(const QString& username);
    QString getRefundInfo(const QString& username);
    bool requestRefund(const QString& username);
    bool joinLoyalty(const QString& username);

    // New Professional Features
    int getTotalGuests() const;
    int getTotalStaff() const;
    int getTotalRooms() const;
    int getBookedRoomsCount() const;
    float calculateEstimatedEarnings() const;
    
    QString getRoomsNeedingCleaning();
    bool markRoomCleaned(int roomNumber);
    bool deleteFeedback(const QString& username);
    bool forceCheckoutCustomer(const QString& username);

signals:
    void loginSuccess(User* user);
    void loginFailed();
    void registrationSuccess();
    void registrationFailed();
};

#endif // HOTELSYSTEM_H
