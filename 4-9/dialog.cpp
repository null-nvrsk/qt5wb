#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->txtEmail->setValidator(validator);

    connect(ui->txtEmail, &QLineEdit::textChanged, this, &Dialog::checkInput);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    if(ui->txtEmail->hasAcceptableInput())
    {
        QMessageBox::information(this, "Email", ui->txtEmail->text());
        accept();
    }
    else
    {
        QMessageBox::critical(this, "Email", "Not valid!");
    }
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::checkInput()
{
    if(ui->txtEmail->hasAcceptableInput())
    {
        ui->txtEmail->setStyleSheet("QLineEdit {color: black;}");
    }
    else
    {
        ui->txtEmail->setStyleSheet("QLineEdit {color: red;}");
    }

}

