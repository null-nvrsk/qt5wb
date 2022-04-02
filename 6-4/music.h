#pragma once

#include <QString>
#include <QDate>

class Music
{
private:
	QString _album;
	QString _artist;
	QString _notes;
	QDate _release;

public:
	QString album() const;
	void setAlbum(const QString& album);

	QString artist() const;
	void setArtist(const QString& artist);

	QString notes() const;
	void setNotes(const QString& notes);

	QDate release() const;
	void setRelease(const QDate& release);


};
