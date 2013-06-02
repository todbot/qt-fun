#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QColor>

#include "blink1-lib.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void messageClicked();
    void updateBlink1();

    void colorChanged(QColor);

    void on_ButtonRGBCycle_clicked();

    void on_ButtonMoodLight_clicked();

    void on_ButtonOff_clicked();

    void on_ButtonOn_clicked();

private:
    void loadSettings();
    void saveSettings();

    void createActions();
    void createTrayIcon();

    Ui::MainWindow *ui;

    QString m_sSettingsFile;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QTimer* blink1timer;
    hid_device* blink1dev;
    uint8_t mode;
    //uint8_t cr,cg,cb;
    QColor cc;
};

#endif // MAINWINDOW_H
