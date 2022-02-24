#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btnNum1, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum2, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum3, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum4, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum5, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum6, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum7, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum8, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum9, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNum0, &QPushButton::clicked, this, &Dialog::append);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::append()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if(!btn) return;

    temp.append(btn->text());
    ui->lblNotify->setText("Typed: " + temp);

    if(code.isEmpty())
    {
        ui->btnSave->setEnabled(true);
        ui->btnVerify->setEnabled(false);
    }
    else
    {
        ui->btnSave->setEnabled(false);
        ui->btnVerify->setEnabled(true);
    }
}

void Dialog::on_btnSave_clicked()
{
    code = temp;
    temp.clear();

    ui->btnSave->setEnabled(false);
    ui->btnVerify->setEnabled(true);

    ui->lblNotify->setText("Code saved, please re-enter the code and click verify");
    QMessageBox::information(this, "Saved", ui->lblNotify->text());
}


void Dialog::on_btnVerify_clicked()
{
    if(temp == code)
    {
        QMessageBox::information(this, "Code", "The codes match!");
    }
    else
    {
        QMessageBox::critical(this, "Code", "The codes do not match!");
    }

    temp.clear();
    ui->lblNotify->setText("Enter the code and click verify");

}

