#include "music.h"

QString Music::album() const
{
	return _album;
}

void Music::setAlbum(const QString& album)
{
	_album = album;
}

QString Music::artist() const
{
	return _artist;
}

void Music::setArtist(const QString& artist)
{
	_artist = artist;
}

QString Music::notes() const
{
	return _notes;
}

void Music::setNotes(const QString& notes)
{
	_notes = notes;
}

QDate Music::release() const
{
	return _release;
}

void Music::setRelease(const QDate& release)
{
	_release = release;
}
