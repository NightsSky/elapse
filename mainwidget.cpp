#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QMouseEvent>
#include <QtDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);//背景透明

    m_areaMovable = geometry();
    m_bPressed = false;
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
//  qDebug() << pos() << e->pos() << m_ptPress;
  m_bPressed = m_areaMovable.contains(m_ptPress);

  }
}

void MainWidget::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
//  qDebug() << pos() << e->pos() << m_ptPress;

  move(pos() + e->pos() - m_ptPress);
  }
}

void MainWidget::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void MainWidget::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
    m_areaMovable = rt;
  }
}
