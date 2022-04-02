#pragma once

#include <QDialog>
#include "ui_editor.h"
#include "music.h"

class Editor : public QDialog
{
	Q_OBJECT

public:
	Editor(QWidget *parent = Q_NULLPTR);
	~Editor();


	Music music() const;
	void setMusic(const Music& music);

private slots:
	void on_buttonBox_accepted();
	void on_buttonBox_rejected();

private:
	Ui::Editor ui;
	Music _music;
};
