#pragma once

#include <QtWidgets/QDialog>
#include <QMessageBox>
#include "ui_dialog.h"
#include "selections.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = Q_NULLPTR);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_btnSelect_clicked();


private:
    Ui::DialogClass ui;
};
