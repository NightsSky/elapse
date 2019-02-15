#ifndef OUTWORKDIALOG_H
#define OUTWORKDIALOG_H

#include <QDialog>

namespace Ui {
class OutWorkDialog;
}

class OutWorkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutWorkDialog(QWidget *parent = nullptr);
    ~OutWorkDialog();

private:
    Ui::OutWorkDialog *ui;
};

#endif // OUTWORKDIALOG_H
