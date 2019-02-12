#include "aboutdialog.h"
#include "mainsettingwindow.h"
#include "timewidget.h"
#include "ui_mainsettingwindow.h"
#include "worktimesetwidget.h"

#include <QDebug>

MainSettingWindow::MainSettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSettingWindow)
{
    ui->setupUi(this);
    systemSmall();
    workTimeSetWidget *workWidget = new workTimeSetWidget(this);

    ui->stackedWidget->addWidget(workWidget);
    ui->stackedWidget->setCurrentWidget(workWidget);


}

MainSettingWindow::~MainSettingWindow()
{
    delete ui;
}

void MainSettingWindow::systemSmall(){

    //新建QSystemTrayIcon对象
        mSysTrayIcon = new QSystemTrayIcon(this);
        //新建托盘要显示的icon
        QIcon icon = QIcon(":/images/myicon.jpg");
        //将icon设到QSystemTrayIcon对象中
        mSysTrayIcon->setIcon(icon);
        //当鼠标移动到托盘上的图标时，会显示此处设置的内容
        mSysTrayIcon->setToolTip(QObject::tr("WHOAMI Elapse"));


        m_menu = new QMenu(this);
        m_action1 = new QAction(m_menu);
        m_action2 = new QAction(m_menu);

        m_action1->setText(QObject::tr("设置"));
        m_action2->setText(QObject::tr("退出 Elapse"));

        m_menu->addAction(m_action1);
        m_menu->addAction(m_action2);

        connect(m_action1, &QAction::triggered, this, &MainSettingWindow::set);
        connect(m_action2, &QAction::triggered, this, &MainSettingWindow::exitApp);

        mSysTrayIcon->setContextMenu(m_menu);


        //在系统托盘显示此对象
        mSysTrayIcon->show();

}

void MainSettingWindow::exitApp()
{
    exit(0);
}

void MainSettingWindow::set()
{
    this->show();
}

void MainSettingWindow::on_about_triggered()
{
    AboutDialog about;
    about.exec();
}
