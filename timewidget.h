#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QSettings>
#include <QWidget>
#include <qsystemtrayicon.h>

namespace Ui {
class TimeWidget;
}

class TimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimeWidget(QWidget *parent = nullptr);
    ~TimeWidget();
    void setAreaMovable(const QRect rt);


private:
    Ui::TimeWidget *ui;
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
    QSettings *setting;
    int workTime;
    int countTime;//工作总时间

    void initView();


private slots:
    void timerUpDate();
    void activeTray(QSystemTrayIcon::ActivationReason reason);

protected:
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);


};

#endif // TIMEWIDGET_H
