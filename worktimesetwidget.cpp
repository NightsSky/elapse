#include "worktimesetwidget.h"
#include "ui_worktimesetwidget.h"
#include "mainsettingwindow.h"
#include <QDebug>


workTimeSetWidget::workTimeSetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::workTimeSetWidget)
{
    ui->setupUi(this);
    setting = new QSettings("./ElapseData.ini", QSettings::IniFormat);
    initView();
   // ptr = qobject_cast<MainSettingWindow*>(parent);
}

workTimeSetWidget::~workTimeSetWidget()
{
    delete ui;
}
void workTimeSetWidget::initView()
{
    if(!setting->childKeys().contains("gowork"))//判断是否有该键，表示第一次进入
    {
        return;
    }
   QStringList goworkSplit = setting->value("gowork").toString().split(":");
   QStringList afterworkSplit = setting->value("afterwork").toString().split(":");
   ui->goWorkTime->setTime(QTime(goworkSplit.at(0).toInt(),goworkSplit.at(1).toInt(),00,000));
   ui->afterWorkTime->setTime(QTime(afterworkSplit.at(0).toInt(),afterworkSplit.at(1).toInt(),00,000));

}
void workTimeSetWidget::on_okBtn_clicked()
{
    if(nullptr != t ){

        setting->setValue("timex",t->geometry().x());
        setting->setValue("timey",t->geometry().y());
        t->close();
    }
    t = new TimeWidget(this);

    t->show();
    int x = setting->value("timex").toInt();
    int y = setting->value("timey").toInt();
    qDebug()<<x<<y;
    if(x!=0&&y!=0){
        t->move(x,y);
    }

    // 获得父部件指针，同时需要类型强转.此处有点坑
    MainSettingWindow *ptr = (MainSettingWindow *)(parentWidget()->parentWidget()->parentWidget());
    ptr->hide(); //ptr就是主窗口的指针，可以用来操作主窗口

}

void workTimeSetWidget::on_saveBtn_clicked()
{
    setting->setValue("gowork",ui->goWorkTime->text());
    setting->setValue("afterwork",ui->afterWorkTime->text());
}
