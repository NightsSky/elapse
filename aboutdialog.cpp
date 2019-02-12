#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->aboutLabel->setText("无聊之作，随缘更新\n第一版本基本功能完成\nXKL");
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
