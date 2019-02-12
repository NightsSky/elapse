#ifndef WORKTIMESETWIDGET_H
#define WORKTIMESETWIDGET_H

#include "mainsettingwindow.h"
#include "timewidget.h"

#include <QWidget>
#include <qsettings.h>

namespace Ui {
class workTimeSetWidget;
}

class workTimeSetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit workTimeSetWidget(QWidget *parent = nullptr);
    ~workTimeSetWidget();

private slots:
    void on_okBtn_clicked();

    void on_saveBtn_clicked();

private:
    Ui::workTimeSetWidget *ui;
    MainSettingWindow *ptr;
    QSettings *setting;
    TimeWidget *t = nullptr;
    void initView();

};

#endif // WORKTIMESETWIDGET_H
