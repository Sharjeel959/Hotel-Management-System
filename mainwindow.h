#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hotelsystem.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT
    HotelSystem *hotel;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openAdminPortal();
    void openGuestPortal();
};

#endif // MAINWINDOW_H
