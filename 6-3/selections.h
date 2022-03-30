#pragma once

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QListWidgetItem>

#include "ui_selections.h"

class Selections : public QDialog
{
	Q_OBJECT

public:
	Selections(QWidget *parent = Q_NULLPTR);
	~Selections();

	QString selected();
	void setSelected(QString value);

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

private:
	Ui::Selections ui;

	QString _selected;
	void init();
};
