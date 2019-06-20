#include "id3v2_3getter.h"
#include <QFile>
#include <iostream>
#include <fstream>
#include "common.h"

using namespace std;

ID3V2_3Getter::ID3V2_3Getter(const QString& filepath)
{
    id3Valid = false;
    initID3V2_header(filepath);
    readTagFrame(filepath);
}

bool ID3V2_3Getter::isId3Valid()
{
    return id3Valid;
}

ID3V1_header ID3V2_3Getter::getHeader1()
{
    return  header1;
}

ID3V2_header ID3V2_3Getter::getHeader2()
{
    return  header2;
}

void ID3V2_3Getter::initID3V2_header(const QString& filepath)
{
    QFile file(filepath);
    if(!file.exists())
        return ;
    if(!file.open(QIODevice::ReadOnly))
        return ;

    file.read(header2.header, ID3V2_headerheaderL);
    if(strcmp(header2.header, "ID3") == 0)
        id3Valid = true;
    else
        return;
    file.read(header2.version, GONE);
    file.read(header2.revision, GONE);
    file.read(header2.flag, GONE);

    file.read(header2.size, ID3V2_headersizeL);
    ID3V2_TagFrame_size = (header2.size[0]&0x7F)*0x200000+(header2.size[1]&0x7F)*0x400+(header2.size[2]&0x7F)*0x80+(header2.size[3]&0x7F);
    file.close();
}

QString ID3V2_3Getter::getGenre()
{
    return genre;
}

ID3V2_TagFrame initTagFrame(const char* srcdata)
{
    ID3V2_TagFrame ret;
    int pos = 0;
    memcpy(ret.id, srcdata+pos, ID3V2_TagFrameidL);
    pos += ID3V2_TagFrameidL;
    memcpy(ret.size, srcdata+pos, ID3V2_TagFramesizeL);
    pos += ID3V2_TagFramesizeL;
    memcpy(ret.flags, srcdata+pos, ID3V2_TagFrameflagsL);
//    DEBUGOUT("ret.id");
//    DEBUGOUT(ret.id);
//    DEBUGOUT("ret.size");
    ret.isize =  ret.size[0]*0x100000000 + ret.size[1]*0x10000+ ret.size[2]*0x100 + ret.size[3];
//    DEBUGOUT(ret.isize);
//    DEBUGOUT("ret.flags");
//    DEBUGOUT(ret.flags);

    ret.tag_volit  = getBit(ret.flags[0],7);
    ret.file_volit = getBit(ret.flags[0],6);
    ret.readonly   = getBit(ret.flags[0],5);
    ret.packed     = getBit(ret.flags[1],7);
    ret.encrypted  = getBit(ret.flags[1],6);
    ret.grouped    = getBit(ret.flags[1],5);

    return  ret;
}

void ID3V2_3Getter::initID3V1_header(int tagid, const char* tagdata)
{

}

void ID3V2_3Getter::readTagFrame(const QString& filepath)
{
    if(!id3Valid)
        return;

    wfstream filei(filepath.toLocal8Bit());
    if(!filei)
    {
        DEBUGOUT("err");
        return;
    }

    DEBUGOUT(ID3V2_TagFrame_size);
    wchar_t* wcone = new wchar_t[1];
    wchar_t* allframe = new wchar_t[ID3V2_TagFrame_size];
    wstring wstr;
    int i = 0;
    while(!filei.eof()&&filei.peek()!=EOF)
    {
        filei.read(wcone, 1);
        wmemcpy(allframe+i, wcone, 1);
        wstr+= wcone;
        i++;
        //DEBUGOUT(i);
        if(i >= ID3V2_TagFrame_size)
            break;
    }

//    QByteArray allframe =
//    DEBUGOUT(allframe);
//    if(allframe.size() != (ID3V2_TagFrame_size - ID3V2_headerL))
//        return;

    int tagid;
    ID3V2_TagFrame tagframe;
    DEBUGOUT("end");
}
