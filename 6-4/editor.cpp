#include "editor.h"

Editor::Editor(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Editor::~Editor()
{
}

void Editor::on_buttonBox_accepted()
{
	_music.setAlbum(ui.txtAlbum->text());
	_music.setArtist(ui.txtArtist->text());
	_music.setRelease(ui.deRelease->date());
	_music.setNotes(ui.txtNote->toPlainText());

	accept();
}

void Editor::on_buttonBox_rejected()
{
	reject();
}

Music Editor::music() const
{
	return _music;
}

void Editor::setMusic(const Music& music)
{
	_music = music;

	ui.txtArtist->setText(_music.artist());
	ui.txtAlbum->setText(_music.album());
	ui.deRelease->setDate(_music.release());
	ui.txtNote->setPlainText(_music.notes());
}
