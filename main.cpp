#include "widget.h"
#include <iostream>
#include <QTextCodec>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    QString fname = QObject::tr("D:/KuGou/陈慧琳 - 记事本.mp3");
    av_register_all();
    avcodec_register_all();
    AVFormatContext* m_AVFormatContext;
    int result = avformat_open_input(&m_AVFormatContext, fname.toLocal8Bit().data(), nullptr, nullptr);
    if (result != 0 || m_AVFormatContext == nullptr)
        return false;

    // 查找流信息，把它存入AVFormatContext中
     if (avformat_find_stream_info(m_AVFormatContext, nullptr) < 0)
        return false;

    int streamsCount = m_AVFormatContext->nb_streams;
    // 读取详细信息
    AVDictionaryEntry *tag = nullptr;
    while (tag = av_dict_get(m_AVFormatContext->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))
    {
        QString keyString = tag->key;
        QString valueString = QString(tag->value);
        DEBUGOUT(keyString);
        DEBUGOUT(valueString);
    }


    return a.exec();
}
