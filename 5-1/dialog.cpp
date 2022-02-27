#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton *btnAccept = new QPushButton(QIcon(":/dialog/images/accept.png"), "Accept", this);
    QPushButton *btnCancel = new QPushButton("Cancel", this);
    btnCancel->setIcon(QIcon(":/dialog/images/cancel.png"));

    ui->buttonBox->addButton(btnAccept, QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(btnCancel, QDialogButtonBox::ButtonRole::RejectRole);

    connect(btnAccept, &QPushButton::clicked, this, &Dialog::acceptMe);
    connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);

    m_saved = true;
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnNew_clicked()
{
    ui->plainTextEdit->clear();
    m_saved = true;
}


void Dialog::on_btnOpen_clicked()
{
    load();
}


void Dialog::on_btnSave_clicked()
{
    save();
    QMessageBox::information(this, "Saved", "Your changes have been saved!");
}

void Dialog::load()
{
    QFile file("file.txt");
    if(!file.exists()) return;

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    m_saved = true;
    file.close();
}

void Dialog::save()
{
    QFile file("file.txt");

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    m_saved = true;
    file.close();
}

void Dialog::closeEvent(QCloseEvent *event)
{
    if(!m_saved)
    {
        QMessageBox::StandardButton btn = QMessageBox::question(this, "Save file?", "Your file has changed, whould you like to save it?");
        if(btn == QMessageBox::StandardButton::Yes)
            save();
    }
    event->accept();
}


void Dialog::on_plainTextEdit_textChanged()
{
    m_saved = false;
}

void Dialog::acceptMe()
{
    save();
    accept();
}

