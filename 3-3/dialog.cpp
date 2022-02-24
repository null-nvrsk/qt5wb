#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCancel_clicked()
{
    QMessageBox::critical(this, "WHAT!?", "You do not want icecream???");
    reject();
}


void Dialog::on_btnOk_clicked()
{
    QString icecream = getOption(ui->grpIceCream);
    QString toppings = getOption(ui->grpToppings);
    QString syrup = getOption(ui->grpSyrup);
    QString size = getOption(ui->grpSize);

    QString order = "Order:\r\n";
    order += "Size: " + size + "\r\n";
    order += "Flavor: " + icecream + "\r\n";
    order += "Topping: " + toppings + "\r\n";
    order += "Syrop: " + syrup;


    QMessageBox::information(this, "Your order", order);

    accept();
}

QString Dialog::getOption(QObject *obj)
{
    QString value = "None";
    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);

    foreach(QRadioButton* rdo, lst)
    {
        if(rdo->isChecked())
        {
            value = rdo->text();
            break;
        }
    }

    return value;
}

