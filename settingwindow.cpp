#include "settingwindow.h"
#include "timewidget.h"
#include "ui_settingwindow.h"
#include <QMouseEvent>
#include <qsettings.h>

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    QSettings setting("./ElapseData.ini", QSettings::IniFormat);

    setting.setValue("pos", "6666666");
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::closeEvent(QCloseEvent *event)
{

}

