#pragma once

#include <QtWidgets/QDialog>
#include "ui_dialog.h"
#include "dialog2.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = Q_NULLPTR);

private slots:
    void on_btnWithParent_clicked();
    void on_btnWithoutParent_clicked();

private:
    Ui::DialogClass ui;
};
