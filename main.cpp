#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("Grand Horizon Hotel System");

    // ═══════════════════════════════════════════════════════════════════════
    //  GRAND HORIZON — Exact design from grand_horizon_enhanced.html
    //  Colors: bg-deep #080c14 | bg-card #0e1523 | bg-panel #111a2e
    //          accent-gold #c9a84c | accent-blue #4a8fe8 | teal #2dd4bf
    //          text-primary #eef2ff | text-secondary #8896b3
    // ═══════════════════════════════════════════════════════════════════════
    app.setStyleSheet(R"(

      /* ── Base ────────────────────────────────────────────────────────── */
      QWidget {
          background-color: #080c14;
          color: #eef2ff;
          font-family: 'Segoe UI', 'DM Sans', system-ui, sans-serif;
          font-size: 13px;
      }
      QMainWindow, QDialog {
          background-color: #080c14;
      }

      /* ── Group Box ───────────────────────────────────────────────────── */
      QGroupBox {
          background-color: #0e1523;
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 10px;
          margin-top: 20px;
          padding: 16px 12px 12px 12px;
          color: #8896b3;
          font-size: 10px;
          letter-spacing: 1.5px;
          text-transform: uppercase;
          font-weight: 600;
      }
      QGroupBox::title {
          subcontrol-origin: margin;
          subcontrol-position: top left;
          padding: 0 8px;
          color: #c9a84c;
      }

      /* ── Labels ──────────────────────────────────────────────────────── */
      QLabel {
          color: #eef2ff;
          background: transparent;
      }

      /* ── Inputs ──────────────────────────────────────────────────────── */
      QLineEdit, QTextEdit, QPlainTextEdit {
          background-color: #111a2e;
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 8px;
          padding: 9px 14px;
          color: #eef2ff;
          font-size: 14px;
          selection-background-color: #4a8fe8;
          qproperty-cursor: 1; /* IBeamCursor */
      }
      QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus {
          border: 1px solid #4a8fe8;
          background-color: #111a2e;
      }

      QComboBox {
          background-color: #111a2e;
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 8px;
          padding: 8px 14px;
          color: #eef2ff;
          font-size: 14px;
          min-height: 36px;
          qproperty-cursor: 13; /* PointingHandCursor */
      }
      QComboBox:focus { border: 1px solid #4a8fe8; }
      QComboBox::drop-down { border: none; width: 24px; }
      QComboBox QAbstractItemView {
          background-color: #0e1523;
          border: 1px solid rgba(255,255,255,0.07);
          color: #eef2ff;
          selection-background-color: #4a8fe8;
          border-radius: 8px;
      }

      QSpinBox, QDoubleSpinBox {
          background-color: #111a2e;
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 8px;
          padding: 8px 14px;
          color: #eef2ff;
          qproperty-cursor: 13;
      }
      QSpinBox:focus, QDoubleSpinBox:focus { border: 1px solid #4a8fe8; }

      /* ── Primary Button (blue) ───────────────────────────────────────── */
      QPushButton {
          background: linear-gradient(135deg, #4a8fe8, #3366cc);
          border: 1px solid rgba(74,143,232,0.4);
          border-radius: 10px;
          padding: 10px 24px;
          color: #ffffff;
          font-weight: 600;
          font-size: 13px;
          min-height: 36px;
          qproperty-cursor: 13; /* PointingHandCursor */
      }
      QPushButton:hover {
          background: linear-gradient(135deg, #5a9ff8, #4a8fe8);
          border-color: #4a8fe8;
      }
      QPushButton:pressed {
          background: #1a3366;
      }
      QPushButton:disabled {
          background: #111a2e;
          border-color: rgba(255,255,255,0.05);
          color: #8896b3;
          qproperty-cursor: 0; /* ArrowCursor */
      }

      /* Gold accent button */
      QPushButton[class="gold"] {
          background: linear-gradient(135deg, #c9a84c, #a88430);
          border-color: rgba(201,168,76,0.5);
      }
      QPushButton[class="gold"]:hover { background: linear-gradient(135deg, #e8c97a, #c9a84c); }

      /* Danger button */
      QPushButton[class="danger"] {
          background: transparent;
          border: 1px solid rgba(224,82,82,0.4);
          color: #e05252;
      }
      QPushButton[class="danger"]:hover { background: rgba(224,82,82,0.1); border-color: #e05252; }

      /* Logout/secondary button */
      QPushButton[class="logout"] {
          background: rgba(255,255,255,0.03);
          border: 1px solid rgba(255,255,255,0.07);
          color: #8896b3;
          border-radius: 10px;
      }
      QPushButton[class="logout"]:hover { background: rgba(255,255,255,0.06); color: #eef2ff; }

      /* Nav button (sidebar) */
      QPushButton[class="nav"] {
          background: transparent;
          border: none;
          color: #8896b3;
          border-radius: 10px;
          text-align: left;
          padding: 11px 14px;
          font-size: 14px;
          font-weight: 500;
      }
      QPushButton[class="nav"]:hover { background: rgba(255,255,255,0.05); color: #eef2ff; }
      QPushButton[class="nav"]:checked { background: rgba(74,143,232,0.12); color: #4a8fe8; font-weight: 600; }

      /* ── Table ───────────────────────────────────────────────────────── */
      QTableWidget {
          background-color: #0e1523;
          alternate-background-color: #111a2e;
          gridline-color: rgba(255,255,255,0.05);
          color: #eef2ff;
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 10px;
          selection-background-color: rgba(74,143,232,0.2);
          selection-color: #eef2ff;
          font-size: 13px;
      }
      QTableWidget::item {
          padding: 10px 14px;
          border-bottom: 1px solid rgba(255,255,255,0.04);
      }
      QHeaderView::section {
          background-color: #0e1523;
          color: #8896b3;
          font-weight: 600;
          font-size: 11px;
          padding: 10px 14px;
          border: none;
          border-bottom: 1px solid rgba(255,255,255,0.07);
          letter-spacing: 0.5px;
      }

      /* ── List Widget ──────────────────────────────────────────────── */
      QListWidget {
          background-color: #0e1523;
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 10px;
          color: #eef2ff;
      }
      QListWidget::item {
          padding: 10px 14px;
          border-bottom: 1px solid rgba(255,255,255,0.04);
      }
      QListWidget::item:selected { background: rgba(74,143,232,0.15); color: #4a8fe8; }
      QListWidget::item:hover { background: rgba(255,255,255,0.03); }

      /* ── Tab Widget ──────────────────────────────────────────────────── */
      QTabWidget::pane {
          border: 1px solid rgba(255,255,255,0.07);
          border-radius: 0 10px 10px 10px;
          background: #0e1523;
          top: -1px;
      }
      QTabBar::tab {
          background: #080c14;
          border: 1px solid rgba(255,255,255,0.07);
          border-bottom: none;
          border-radius: 8px 8px 0 0;
          padding: 9px 20px;
          color: #8896b3;
          margin-right: 2px;
      }
      QTabBar::tab:selected { background: #0e1523; color: #4a8fe8; border-bottom: 2px solid #4a8fe8; }
      QTabBar::tab:hover:!selected { color: #eef2ff; }

      /* ── Scroll Bar ──────────────────────────────────────────────────── */
      QScrollBar:vertical {
          background: #080c14;
          width: 4px;
          border-radius: 2px;
      }
      QScrollBar::handle:vertical {
          background: rgba(255,255,255,0.08);
          border-radius: 2px;
          min-height: 20px;
      }
      QScrollBar::handle:vertical:hover { background: rgba(255,255,255,0.15); }
      QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { border: none; background: none; }
      QScrollBar:horizontal { background: #080c14; height: 4px; border-radius: 2px; }
      QScrollBar::handle:horizontal { background: rgba(255,255,255,0.08); border-radius: 2px; min-width: 20px; }
      QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { border: none; background: none; }

      /* ── Message Box ─────────────────────────────────────────────────── */
      QMessageBox { background-color: #0e1523; border: 1px solid rgba(255,255,255,0.07); }
      QMessageBox QLabel { color: #eef2ff; font-size: 13px; }
      QMessageBox QPushButton { min-width: 80px; }

      /* ── Menu / Status ───────────────────────────────────────────────── */
      QMenuBar { background: #0e1523; color: #eef2ff; border-bottom: 1px solid rgba(255,255,255,0.07); }
      QMenuBar::item:selected { background: #4a8fe8; border-radius: 4px; }
      QMenu { background: #0e1523; border: 1px solid rgba(255,255,255,0.07); border-radius: 8px; }
      QMenu::item { padding: 8px 24px; color: #eef2ff; }
      QMenu::item:selected { background: rgba(74,143,232,0.2); }
      QStatusBar { background: #0e1523; color: #8896b3; border-top: 1px solid rgba(255,255,255,0.07); }
    )");

    MainWindow *window = new MainWindow(nullptr);
    window->show();

    return app.exec();
}
