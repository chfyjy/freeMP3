#ifndef ID3V1GETTER_H
#define ID3V1GETTER_H

#include<QString>
#include "mediatag.h"

class ID3V1Getter
{
public:
    ID3V1Getter(const QString& filepath);
    bool isId3Valid();
    ID3V1_header getHeader();
    QString getGenre();
private:
    QByteArray readId3v1Data(const QString& filepath);
    void initID3V1Header(const QByteArray& id3v1Data);

private:
    bool id3Valid;
    ID3V1_header header;
    QString genre;
};

#endif // ID3V1GETTER_H
