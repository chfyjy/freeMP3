#include "metadatageter.h"
#include <QFile>


MetaDataGeter::MetaDataGeter(const QString& filepath)
{
    this->filepath = filepath;
    id3v1Data.clear();
    id3Valid = false;
    readId3v1Data();
    initId3V1AudioInfo();
}

bool MetaDataGeter::isId3Valid()
{
    return  id3Valid;
}

void MetaDataGeter::readId3v1Data()
{
    QFile file(filepath);
    if(!file.exists())
        return;
    if(!file.open(QIODevice::ReadOnly))
        return;
    file.seek(file.size()-id3V1DataL);
    id3v1Data = file.read(id3V1DataL);
    QByteArray tagData = id3v1Data.left(id3TagL);
    if(tagData == id3v1Tag)
        id3Valid = true;
    file.close();
}

void MetaDataGeter::initId3V1AudioInfo()
{
    if(!id3Valid)
        return;
    ID3V1_header header;
    int startpos = 0;
    char* tmpdata = id3v1Data.data();
    memcpy( header.header,tmpdata+startpos, id3TagL);
    startpos += id3TagL;
    memcpy( header.title,tmpdata+startpos, id3TitleL);
    startpos += id3TitleL;
    memcpy( header.artist,tmpdata+startpos, id3ArtistL);
    startpos += id3ArtistL;
    memcpy( header.album,tmpdata+startpos, id3albumL);
    startpos += id3albumL;
    memcpy( header.year,tmpdata+startpos, id3YearL);
    startpos += id3YearL;
    memcpy( header.comment,tmpdata+startpos, id3CommentL);
    startpos += id3CommentL;
    memcpy(header.reserve, tmpdata+startpos, GONE);
    startpos += GONE;
    memcpy(header.track, tmpdata+startpos, GONE);
    startpos += GONE;
    memcpy(header.genre, tmpdata+startpos, GONE);
    startpos += GONE;
    initInfoById3V1(header);
}

void MetaDataGeter::initInfoById3V1(ID3V1_header header)
{
    info.year = QString(header.year);
    info.title = QString(header.title);
    info.artist = QString(header.artist);
    info.album = QString(header.album);
    info.genre = genreMap[(int)(header.genre[0])];
    info.track = (int)(header.track[0]);
}
