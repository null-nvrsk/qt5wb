#include "dialog2.h"

Dialog2::Dialog2(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Dialog2::~Dialog2()
{
}

void Dialog2::on_btnClose_clicked()
{
	accept();
}