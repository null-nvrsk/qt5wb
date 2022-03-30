#include "selections.h"

Selections::Selections(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	init();
}

Selections::~Selections()
{
}

QString Selections::selected()
{
	return _selected;
}

void Selections::setSelected(QString value)
{
	_selected = "";

	for (int i = 0; i < ui.listWidget->count(); ++i)
	{
		QListWidgetItem* item = ui.listWidget->item(i);
		if (item->text() == value)
		{
			item->setSelected(true);
			_selected = value;
			return;
		}
	}
}

void Selections::on_buttonBox_accepted()
{
	_selected = ui.listWidget->currentItem()->text();

	accept();
}

void Selections::on_buttonBox_rejected()
{
	reject();
}

void Selections::init()
{
	QDir root = QDir(":/file/images");

	QFileInfoList list = root.entryInfoList();
	foreach(QFileInfo fi, list)
	{
		QListWidgetItem* item = new QListWidgetItem();
		item->setText(fi.absoluteFilePath());
		item->setIcon(QIcon(fi.absoluteFilePath()));
		ui.listWidget->addItem(item);
	}

}
