#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    MyLib myLib;
    ui->lineEdit->setText(myLib.message());

    QPixmap img(":/files/images/accept.png");
    ui->label->setPixmap(img);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}

