#ifndef ID3V2_3GETTER_H
#define ID3V2_3GETTER_H

#include<QString>
#include "mediatag.h"

class ID3V2_3Getter
{
public:
    ID3V2_3Getter(const QString& filepath);
    bool isId3Valid();
    ID3V1_header getHeader1();
    ID3V2_header getHeader2();
    QString getGenre();
private:
    void initID3V2_header(const QString& filepath);
    void readTagFrame(const QString& filepath);
    void initID3V1_header(int tagid, const char* tagdata);
private:
    bool id3Valid;
    ID3V1_header header1;
    ID3V2_header header2;
    int ID3V2_TagFrame_size;
    QString genre;
};

#endif // ID3V2_3GETTER_H
