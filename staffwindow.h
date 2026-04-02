#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include "hotelsystem.h"
#include <QDialog>
#include <QPushButton>
#include <QString>
#include <QTextEdit>


class StaffWindow : public QDialog {
  Q_OBJECT
  HotelSystem *hotel;
  QString username;
  QTextEdit *displayArea;
  QPushButton *viewInfoButton;
  QPushButton *logoutButton;

public:
  StaffWindow(HotelSystem *hotel, const QString &username,
              QWidget *parent = nullptr);

private slots:
  void viewInfo();
};

#endif
