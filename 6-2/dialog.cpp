#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

void Dialog::on_btnWithParent_clicked()
{
    Dialog2* dialog = new Dialog2(this);
    dialog->exec();
}


void Dialog::on_btnWithoutParent_clicked()
{
    // pointer does not delete itself!!!
    Dialog2* dialog = new Dialog2(nullptr);
    dialog->exec();
}
