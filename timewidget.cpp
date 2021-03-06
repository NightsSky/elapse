#include "mainwidget.h"
#include "mainsettingwindow.h"
#include "timewidget.h"
#include "ui_timewidget.h"
#include <QMenu>
#include <QMouseEvent>
#include "outworkdialog.h"


#include <QtCore>

TimeWidget::TimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeWidget)
{
    ui->setupUi(this);
    ui->menuList->setVisible(false);
    this->setWindowFlags(Qt::Tool|Qt::FramelessWindowHint);
//    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);//背景透明

    setting = new QSettings("./ElapseData.ini", QSettings::IniFormat);
    m_areaMovable = geometry();
    m_bPressed = false;

    timer = new QTimer(this);
    //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //关联定时器计满信号和相应的槽函数
    timer->start(1000);
    //定时器开始计时，其中1000表示1000ms即1秒./
    initView();

}

TimeWidget::~TimeWidget()
{
    delete ui;
}

void TimeWidget::timerUpDate()

{

    QDateTime time = QDateTime::currentDateTime();

    //获取系统现在的时间

    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");

    //设置系统时间显示格式

    if(workTime>0)
    {
        ui->timeLabel->setText(str);
        ui->timeNeed->setText(QString::number(workTime--));


        int percentage = workTime*100/countTime;
        ui->timeProgress->setValue(100-percentage);
    }else if(workTime==0) {

        OutWorkDialog *outDialog = new OutWorkDialog(this);
        outDialog->show();
        outDialog->move(600,400);
     }


}
void TimeWidget::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
//  qDebug() << pos() << e->pos() << m_ptPress;
  m_bPressed = m_areaMovable.contains(m_ptPress);

  }else if (e->button() == Qt::RightButton) {//鼠标右键
       ui->menuList->setVisible(true);
  }
}

void TimeWidget::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
//  qDebug() << pos() << e->pos() << m_ptPress;

  move(pos() + e->pos() - m_ptPress);
  }
}

void TimeWidget::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void TimeWidget::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
    m_areaMovable = rt;
  }
}

void TimeWidget::initView()
{
    QTime currentTime = QTime::currentTime();
    QStringList goworkSplit = setting->value("gowork").toString().split(":");//上班时间
    QStringList afterworkSplit = setting->value("afterwork").toString().split(":");//下半时间
    QTime goworkTime = QTime(goworkSplit.at(0).toInt(),goworkSplit.at(1).toInt(),00,000);
    QTime afterworkTime = QTime(afterworkSplit.at(0).toInt(),afterworkSplit.at(1).toInt(),00,000);
    countTime = goworkTime.secsTo(afterworkTime);
    qDebug()<<countTime;
    if(currentTime>=goworkTime&&currentTime<afterworkTime)
    {//上班时间
        QTime m_time;
        m_time.setHMS(0, 0, 0, 0);                                       //初始化数据，时 分 秒 毫秒
//        m_time.addSecs(currentTime.secsTo(afterworkTime)).toString("hh:mm:ss");//计算时间差(秒)，将时间差加入m_time，格式化输出
        workTime = currentTime.secsTo(afterworkTime);

        ui->label->setText("离下班还有:");

    }else
    {
        ui->label->setText("离上班还有:");
        ui->timeProgress->hide();
        if(currentTime<goworkTime)
        {
            workTime = currentTime.secsTo(goworkTime);
        }else {
            workTime = currentTime.secsTo(QTime(24,00,00,000))+9*3600;
        }
    }
//    ui->timeLabel->hide();
}




void TimeWidget::activeTray(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
        {
        case QSystemTrayIcon::Context:
//            showMenu();
            break;
        case QSystemTrayIcon::DoubleClick:
//            showWindow();
            break;
        case QSystemTrayIcon::Trigger:
//            showMessage();
            break;
        }


}


