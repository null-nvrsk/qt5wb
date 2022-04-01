#include "dialog.h"

Dialog::Dialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Dialog::~Dialog()
{
}

QString Dialog::selected() const
{
	return _selected;
}

void Dialog::setList(QStringList list)
{  
	ui.comboBox->addItems(list);
}
 
void Dialog::on_buttonBox_accepted()
{
	_selected = ui.comboBox->currentText(); 

	accept();
}

void Dialog::on_buttonBox_rejected()
{
	reject();
}
