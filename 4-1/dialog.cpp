#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->lblSelected->setText(QString::number(index) + " = " + ui->comboBox->currentText());
}


void Dialog::on_btnSave_clicked()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setValue("Combo", ui->comboBox->currentIndex());

    QMessageBox::information(this, "Saved", "Selection saved");
}

void Dialog::init()
{
    ui->comboBox->clear();

    for (int i = 0; i < 10; i++)
    {
        ui->comboBox->addItem("Item " + QString::number(i));
    }
}

void Dialog::load()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    QVariant value = settings.value("Combo", 0);

    bool ok;
    int index = value.toInt(&ok);
    if(!ok)
    {
        QMessageBox::critical(this, "Loading error", "Error loading selection");
        return;
    }

    if(index < ui->comboBox->count())
    {
        ui->comboBox->setCurrentIndex(index);
    }
    else
    {
        ui->comboBox->setCurrentIndex(0);
    }
}

