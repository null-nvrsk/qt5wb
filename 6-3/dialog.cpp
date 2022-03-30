#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Selected", "You have selected:\r\n" +
        ui.lineEdit->text());
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_btnSelect_clicked()
{
    Selections* dlg = new Selections(this);
    dlg->setSelected(ui.lineEdit->text());

    dlg->exec();

    // New selection
    ui.lineEdit->setText(dlg->selected());
}
