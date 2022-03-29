#include "dialog2.h"

Dialog2::Dialog2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Dialog2::~Dialog2()
{
}

void Dialog2::on_buttonBox_accepted()
{
	accept();
}

void Dialog2::on_buttonBox_rejected()
{
	reject();
}
