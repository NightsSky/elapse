#include "outworkdialog.h"
#include "ui_outworkdialog.h"

OutWorkDialog::OutWorkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutWorkDialog)
{
    ui->setupUi(this);
}

OutWorkDialog::~OutWorkDialog()
{
    delete ui;
}
