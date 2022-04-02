#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    QPushButton *button = new QPushButton("Edit", this);
    ui.buttonBox->addButton(button, QDialogButtonBox::ButtonRole::ActionRole);
    connect(button, &QPushButton::clicked, this, &Dialog::on_edit);

    _music.setArtist("Linkin Park");
    _music.setAlbum("Meteora");
    _music.setRelease(QDate(2003, 3, 25));
    _music.setNotes("Best LP album");

    load();
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Selection", ui.plainTextEdit->toPlainText());
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_edit()
{
    Editor* dlg = new Editor(this);
    dlg->setMusic(_music);
    dlg->exec();

    _music = dlg->music();

    load();

    delete dlg;
}

void Dialog::load()
{
    ui.plainTextEdit->clear();
    ui.plainTextEdit->setReadOnly(true);

    QString data;
    data.append("Artist: " + _music.artist() + "\r\n");
    data.append("Album: " + _music.album() + "\r\n");
    data.append("Release: " + _music.release().toString() + "\r\n");
    data.append("Notes: " + _music.notes() + "\r\n");

    ui.plainTextEdit->setPlainText(data);
}
