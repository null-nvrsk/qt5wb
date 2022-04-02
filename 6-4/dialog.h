#pragma once

#include <QtWidgets/QDialog>
#include <QPushButton>
#include <QMessageBox>
#include "ui_dialog.h"
#include "editor.h"
#include "music.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = Q_NULLPTR);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void on_edit();


private:
    Ui::DialogClass ui;

    Music _music;
    void load();
};
