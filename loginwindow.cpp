#include "loginwindow.h"
#include "adminwindow.h"
#include "guestwindow.h"
#include "registerwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>

using namespace std;
using namespace Qt;

// ── Color constants from grand_horizon_enhanced.html ─────────────────────────
static const char* BG_CARD    = "#0e1523";
static const char* BG_PANEL   = "#111a2e";
static const char* GOLD       = "#c9a84c";
static const char* BLUE       = "#4a8fe8";
static const char* BORDER     = "rgba(255,255,255,0.07)";
static const char* TEXT_PRI   = "#eef2ff";
static const char* TEXT_SEC   = "#8896b3";

LoginWindow::LoginWindow(HotelSystem *hotel, const QString &expectedRole, QWidget *parent)
    : QDialog(parent), hotel(hotel), expectedRole(expectedRole) {

    QString roleName    = expectedRole.at(0).toUpper() + expectedRole.mid(1);
    bool    isAdmin     = (expectedRole == "admin");
    QString accentColor = isAdmin ? BLUE : GOLD;
    QString iconText    = isAdmin ? "🛡️" : "🏨";

    setWindowTitle("Grand Horizon — " + roleName + " Portal");
    setFixedSize(400, 500);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    // Card background matching #0e1523 (bg-card from HTML)
    setStyleSheet(QString(
        "QDialog { background: %1; border: 1px solid %2; border-radius: 16px; }"
    ).arg(BG_CARD).arg(BORDER));

    QVBoxLayout *root = new QVBoxLayout(this);
    root->setContentsMargins(36, 36, 36, 32);
    root->setSpacing(0);

    // ── Icon + Title ──────────────────────────────────────────────────────
    QLabel *ico = new QLabel(iconText);
    ico->setAlignment(Qt::AlignCenter);
    ico->setStyleSheet("font-size: 40px; background: transparent; color: " + accentColor + ";");

    QLabel *titleL = new QLabel(roleName + " Portal");
    titleL->setAlignment(Qt::AlignCenter);
    titleL->setStyleSheet(QString(
        "font-size: 22px; font-weight: 700; color: %1; background: transparent;").arg(accentColor));

    QLabel *subL = new QLabel("Sign in to your account");
    subL->setAlignment(Qt::AlignCenter);
    subL->setStyleSheet(QString("font-size: 13px; color: %1; background: transparent; margin-bottom: 4px;").arg(TEXT_SEC));

    root->addWidget(ico);
    root->addSpacing(8);
    root->addWidget(titleL);
    root->addWidget(subL);
    root->addSpacing(28);

    // ── Input fields ──────────────────────────────────────────────────────
    auto field = [this](const QString &ph, bool pwd = false) {
        QLineEdit *e = new QLineEdit(this);
        e->setPlaceholderText(ph);
        e->setMinimumHeight(44);
        e->setStyleSheet(QString(
            "QLineEdit { background: %1; border: 1px solid %2; border-radius: 8px;"
            "padding: 0 14px; color: %3; font-size: 14px; }"
            "QLineEdit:focus { border: 1px solid %4; }"
        ).arg(BG_PANEL).arg(BORDER).arg(TEXT_PRI).arg(BLUE));
        if (pwd) e->setEchoMode(QLineEdit::Password);
        return e;
    };

    usernameEdit = field("Username");
    passwordEdit = field("Password", true);

    root->addWidget(usernameEdit);
    root->addSpacing(12);
    root->addWidget(passwordEdit);
    root->addSpacing(20);

    // ── Login Button ──────────────────────────────────────────────────────
    loginButton = new QPushButton("Login");
    loginButton->setMinimumHeight(46);
    loginButton->setStyleSheet(QString(
        "QPushButton { background: %1; border: none; border-radius: 10px;"
        "color: white; font-weight: 700; font-size: 14px; letter-spacing: 0.5px; }"
        "QPushButton:hover { background: %2; }"
        "QPushButton:pressed { background: #0e1523; color: %1; border: 1px solid %1; }"
    ).arg(accentColor).arg(isAdmin ? "#5a9ff8" : "#e8c97a"));

    root->addWidget(loginButton);
    root->addSpacing(14);

    // ── Divider ───────────────────────────────────────────────────────────
    QHBoxLayout *div = new QHBoxLayout();
    auto mkLine = [this]() {
        QFrame *f = new QFrame(); f->setFrameShape(QFrame::HLine);
        f->setStyleSheet(QString("border-top: 1px solid %1; background: transparent;").arg(BORDER));
        return f;
    };
    QLabel *orL = new QLabel("  or  ");
    orL->setStyleSheet(QString("color: %1; font-size: 12px; background: transparent;").arg(TEXT_SEC));
    div->addWidget(mkLine(), 1); div->addWidget(orL); div->addWidget(mkLine(), 1);
    root->addLayout(div);
    root->addSpacing(14);

    // ── Register Button ───────────────────────────────────────────────────
    QPushButton *regBtn = new QPushButton("Create New Account");
    regBtn->setMinimumHeight(44);
    regBtn->setStyleSheet(QString(
        "QPushButton { background: transparent; border: 1px solid %1; border-radius: 10px;"
        "color: %2; font-size: 13px; font-weight: 600; }"
        "QPushButton:hover { background: rgba(255,255,255,0.04); border-color: rgba(255,255,255,0.15); color: %3; }"
    ).arg(BORDER).arg(TEXT_SEC).arg(TEXT_PRI));

    root->addWidget(regBtn);
    root->addSpacing(12);

    // ── Cancel link ───────────────────────────────────────────────────────
    cancelButton = new QPushButton("Cancel");
    cancelButton->setMinimumHeight(36);
    cancelButton->setStyleSheet(QString(
        "QPushButton { background: transparent; border: none; color: %1; font-size: 13px; }"
        "QPushButton:hover { color: %2; }").arg(TEXT_SEC).arg(TEXT_PRI));

    root->addWidget(cancelButton);
    root->addStretch();

    // ── Signals ───────────────────────────────────────────────────────────
    connect(loginButton,  &QPushButton::clicked, this, &LoginWindow::attemptLogin);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    connect(regBtn, &QPushButton::clicked, this, [this, hotel, expectedRole]() {
        RegisterWindow regWin(hotel, this);
        regWin.setFixedRole(expectedRole);
        regWin.exec();
    });
    connect(hotel, &HotelSystem::loginSuccess, this, &LoginWindow::handleLoginSuccess);
    connect(hotel, &HotelSystem::loginFailed,  this, &LoginWindow::handleLoginFailed);
}

void LoginWindow::attemptLogin() {
    if (usernameEdit->text().trimmed().isEmpty() || passwordEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Username and Password cannot be empty.");
        return;
    }
    hotel->login(usernameEdit->text(), passwordEdit->text());
}

void LoginWindow::handleLoginSuccess(User *user) {
    if (user->getRole().trimmed() != expectedRole.trimmed()) {
        QMessageBox::critical(this, "Access Denied",
            "Wrong portal. You are registered as: " + user->getRole().toUpper().trimmed());
        return;
    }
    accept();
    if (parentWidget()) parentWidget()->hide();

    if (user->getRole().trimmed() == "admin") {
        AdminWindow w(hotel, parentWidget());
        w.exec();
    } else {
        GuestWindow w(hotel, user->getUsername(), parentWidget());
        w.exec();
    }
    if (parentWidget()) parentWidget()->show();
}

void LoginWindow::handleLoginFailed() {
    QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
}
