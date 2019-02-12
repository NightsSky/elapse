#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    //设置鼠标按下可移动窗口的区域，在子窗口中必须设置该区域
    void setAreaMovable(const QRect rt);

private:
    Ui::MainWidget *ui;

protected:
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);

private:
  QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
  bool m_bPressed;//鼠标按下标志（不分左右键）
  QPoint m_ptPress;//鼠标按下的初始位置

};

#endif // MAINWIDGET_H
