#include <QMessageBox>

#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

void Dialog::on_btnWithParent_clicked()
{
    //QMessageBox::information(this, "Title", "on_btnWithParent_clicked");
    Dialog2* dialog = new Dialog2(this);
    dialog->show();
}

void Dialog::on_btnWithoutParent_clicked()
{
    //QMessageBox::information(this, "Title", "on_btnWithoutParent_clicked");
    Dialog2* dialog = new Dialog2(nullptr);
    dialog->show();
}
