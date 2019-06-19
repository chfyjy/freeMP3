#include "id3v1getter.h"
#include <QFile>

ID3V1Getter::ID3V1Getter(const QString& filepath)
{
    id3Valid = false;
    initID3V1Header(readId3v1Data(filepath));
}

bool ID3V1Getter::isId3Valid()
{
    return  id3Valid;
}

ID3V1_header ID3V1Getter::getHeader()
{
    return  header;
}

QString ID3V1Getter::getGenre()
{
    return genre;
}

QByteArray ID3V1Getter::readId3v1Data(const QString& filepath)
{
    QByteArray id3v1Data;
    QFile file(filepath);
    if(!file.exists())
        return id3v1Data;
    if(!file.open(QIODevice::ReadOnly))
        return id3v1Data;
    file.seek(file.size()-id3V1DataL);
    id3v1Data = file.read(id3V1DataL);
    QByteArray tagData = id3v1Data.left(id3TagL);
    if(tagData == id3v1Tag)
        id3Valid = true;
    file.close();
    return id3v1Data;
}

void ID3V1Getter::initID3V1Header(const QByteArray& id3v1Data)
{
    if(!id3Valid)
        return;
    if(id3v1Data.length() != id3V1DataL)
        return;
    int startpos = 0;
    const char* tmpdata = id3v1Data.data();
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

    genre = genreMap[(int)header.genre[0]];
    //delete tmpdata;
}
