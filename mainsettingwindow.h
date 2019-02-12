#ifndef MAINSETTINGWINDOW_H
#define MAINSETTINGWINDOW_H

#include "timewidget.h"

#include <QAction>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <qsettings.h>


namespace Ui {
class MainSettingWindow;
}

class MainSettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSettingWindow(QWidget *parent = nullptr);
    ~MainSettingWindow();

private slots:

    void on_about_triggered();

private:
    Ui::MainSettingWindow *ui;

    QSystemTrayIcon *mSysTrayIcon;
    QMenu *m_menu;
    QAction *m_action1;
    QAction *m_action2;


    void systemSmall();
    void exitApp();
    void set();


};

#endif // MAINSETTINGWINDOW_H
