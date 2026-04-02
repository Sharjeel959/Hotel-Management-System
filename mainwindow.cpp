#include "mainwindow.h"
#include "loginwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QApplication>
#include <QScreen>

// ── Helper: paint the deep-dark background on this widget ────────────────────
static void setDeepBg(QWidget *w) {
    w->setStyleSheet("background-color: #080c14;");
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    hotel = new HotelSystem();
    setWindowTitle("Grand Horizon Hotel System");
    setMinimumSize(880, 600);

    // Centre on screen
    resize(1050, 680);
    QRect scr = QApplication::primaryScreen()->geometry();
    move(scr.center() - rect().center());

    // ── Root widget ────────────────────────────────────────────────────────
    QWidget *central = new QWidget(this);
    central->setStyleSheet(
        "background: #080c14;"
    );
    setCentralWidget(central);

    QVBoxLayout *root = new QVBoxLayout(central);
    root->setAlignment(Qt::AlignCenter);
    root->setSpacing(0);
    root->setContentsMargins(0, 0, 0, 0);

    root->addStretch(2);

    // ── Brand Badge ──────────────────  (exactly matches .brand-badge in HTML)
    QLabel *badge = new QLabel("✦  Luxury Hotel Management  ✦");
    badge->setAlignment(Qt::AlignCenter);
    badge->setStyleSheet(
        "background: qlineargradient(x1:0,y1:0,x2:1,y2:1,"
        "  stop:0 rgba(201,168,76,0.15), stop:1 rgba(201,168,76,0.05));"
        "border: 1px solid rgba(201,168,76,0.3);"
        "border-radius: 4px;"
        "padding: 5px 18px;"
        "font-size: 11px;"
        "letter-spacing: 3px;"
        "color: #c9a84c;"
        "font-weight: 600;"
    );
    badge->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QHBoxLayout *badgeRow = new QHBoxLayout();
    badgeRow->addStretch();
    badgeRow->addWidget(badge);
    badgeRow->addStretch();
    root->addLayout(badgeRow);
    root->addSpacing(20);

    // ── Brand Name ──────────────── (matches .brand-name, gold gradient)
    QLabel *brandName = new QLabel("GRAND HORIZON");
    brandName->setAlignment(Qt::AlignCenter);
    brandName->setStyleSheet(
        "font-size: 54px;"
        "font-weight: 700;"
        "letter-spacing: 8px;"
        "color: #e8c97a;"   // closest to gold gradient mid-point
        "font-family: 'Segoe UI', Georgia, serif;"
    );
    root->addWidget(brandName);

    // Sub
    QLabel *brandSub = new QLabel("Select your portal to continue");
    brandSub->setAlignment(Qt::AlignCenter);
    brandSub->setStyleSheet(
        "font-size: 13px;"
        "color: #8896b3;"
        "letter-spacing: 2px;"
        "text-transform: uppercase;"
    );
    root->addWidget(brandSub);
    root->addSpacing(48);

    // ── Portal Cards row ────────────────────────────────────────────────────
    QHBoxLayout *cardsRow = new QHBoxLayout();
    cardsRow->setSpacing(20);
    cardsRow->setAlignment(Qt::AlignCenter);

    // Card factory — replicates .portal-card from HTML
    auto makeCard = [this](const QString& icon, const QString& title,
                            const QString& desc, bool isAdmin) -> QFrame*
    {
        QString hoverBorderColor = isAdmin ? "rgba(74,143,232,0.4)" : "rgba(201,168,76,0.4)";
        QString glowColor        = isAdmin ? "rgba(74,143,232,0.15)" : "rgba(201,168,76,0.12)";
        QString gradientColor    = isAdmin ? "rgba(74,143,232,0.10)" : "rgba(201,168,76,0.10)";

        QFrame *card = new QFrame();
        card->setFixedSize(220, 240);
        card->setStyleSheet(QString(
            "QFrame {"
            "  background: #0e1523;"
            "  border: 1px solid rgba(255,255,255,0.07);"
            "  border-radius: 16px;"
            "}"
        ));

        QVBoxLayout *l = new QVBoxLayout(card);
        l->setContentsMargins(24, 32, 24, 28);
        l->setSpacing(8);

        QLabel *ico = new QLabel(icon);
        ico->setAlignment(Qt::AlignCenter);
        ico->setStyleSheet("font-size: 36px; background: transparent; border: none;");

        QLabel *titleLbl = new QLabel(title);
        titleLbl->setAlignment(Qt::AlignCenter);
        titleLbl->setStyleSheet(
            "font-size: 16px; font-weight: 600; color: #eef2ff;"
            "background: transparent; border: none;"
        );

        QLabel *descLbl = new QLabel(desc);
        descLbl->setAlignment(Qt::AlignCenter);
        descLbl->setWordWrap(true);
        descLbl->setStyleSheet(
            "font-size: 12px; color: #8896b3; line-height: 1.5;"
            "background: transparent; border: none;"
        );

        l->addWidget(ico);
        l->addWidget(titleLbl);
        l->addWidget(descLbl);
        l->addStretch();

        return card;
    };

    QFrame *adminCard = makeCard("🛡️", "Admin Portal",
                                  "Manage bookings, staff, rooms &\nanalytics", true);
    QFrame *guestCard = makeCard("🏨", "Guest / Customer",
                                  "Browse rooms, book &\nmanage your stay", false);

    // Make the entire card clickable
    QPushButton *adminBtn = new QPushButton();
    adminBtn->setParent(adminCard);
    adminBtn->setGeometry(0, 0, 220, 240);
    adminBtn->setStyleSheet(
        "QPushButton {"
        "  background: transparent; border: none; border-radius: 16px;"
        "}"
        "QPushButton:hover {"
        "  background: rgba(74,143,232,0.06);"
        "  border: 1px solid rgba(74,143,232,0.3);"
        "  border-radius: 16px;"
        "}"
    );
    adminBtn->raise();

    QPushButton *guestBtn = new QPushButton();
    guestBtn->setParent(guestCard);
    guestBtn->setGeometry(0, 0, 220, 240);
    guestBtn->setStyleSheet(
        "QPushButton {"
        "  background: transparent; border: none; border-radius: 16px;"
        "}"
        "QPushButton:hover {"
        "  background: rgba(201,168,76,0.06);"
        "  border: 1px solid rgba(201,168,76,0.3);"
        "  border-radius: 16px;"
        "}"
    );
    guestBtn->raise();

    connect(adminBtn, &QPushButton::clicked, this, &MainWindow::openAdminPortal);
    connect(guestBtn, &QPushButton::clicked, this, &MainWindow::openGuestPortal);

    cardsRow->addWidget(adminCard);
    cardsRow->addWidget(guestCard);

    root->addLayout(cardsRow);
    root->addSpacing(32);

    // ── Exit Button ─────────── (matches .btn-exit from HTML)
    QPushButton *exitBtn = new QPushButton("✕  Exit System");
    exitBtn->setFixedSize(200, 44);
    exitBtn->setStyleSheet(
        "QPushButton {"
        "  background: transparent;"
        "  border: 1px solid rgba(224,82,82,0.4);"
        "  border-radius: 10px;"
        "  color: #e05252;"
        "  font-size: 14px;"
        "  font-weight: 500;"
        "  letter-spacing: 0.5px;"
        "}"
        "QPushButton:hover {"
        "  background: rgba(224,82,82,0.1);"
        "  border-color: #e05252;"
        "}"
    );
    connect(exitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    QHBoxLayout *exitRow = new QHBoxLayout();
    exitRow->addStretch();
    exitRow->addWidget(exitBtn);
    exitRow->addStretch();
    root->addLayout(exitRow);

    root->addStretch(2);
}

void MainWindow::openAdminPortal() {
    LoginWindow dlg(hotel, "admin", this);
    dlg.exec();
}

void MainWindow::openGuestPortal() {
    LoginWindow dlg(hotel, "guest", this);
    dlg.exec();
}

MainWindow::~MainWindow() {
    delete hotel;
}
