#pragma once

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QComboBox>
#include "ui_dialog.h"

class Dialog : public QDialog
{
	Q_OBJECT

public:
	Dialog(QWidget *parent = Q_NULLPTR);
	~Dialog();

	QString selected() const;
	void setList(QStringList list);

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

private:
	Ui::Dialog ui;
	QString _selected;
};
