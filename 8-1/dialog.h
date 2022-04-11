#pragma once

#include <QtWidgets/QDialog>
#include <QMessageBox>
#include <QGroupBox>
#include "ui_dialog.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = Q_NULLPTR);

private slots: 
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogClass ui;

    QString getOptions(QGroupBox *group);
 };
