#pragma once

#include <QDialog>
#include "ui_dialog2.h"

class Dialog2 : public QDialog
{
	Q_OBJECT

public:
	Dialog2(QWidget *parent = Q_NULLPTR);
	~Dialog2();

private slots:
	void on_btnClose_clicked();

private:
	Ui::Dialog2 ui;
};
