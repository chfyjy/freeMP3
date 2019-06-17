#ifndef METADATAGETER_H
#define METADATAGETER_H

#include "mediatag.h"
//#include "common.h"

class MetaDataGeter
{
public:
    MetaDataGeter(const QString& filepath);

    bool isId3Valid();
private:
    void readId3v1Data();
    void initId3V1AudioInfo();
    void initInfoById3V1(ID3V1_header header);

private:
    QByteArray id3v1Data;
    bool id3Valid;
    QString filepath;
    AudioMediaInfo info;
};

#endif // METADATAGETER_H
