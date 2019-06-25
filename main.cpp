#include "widget.h"
#include "id3v1getter.h"
#include "id3v2_3getter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    QString fname = QObject::tr("D:/KuGou/80000_音乐热搜.mp3");
    //QString fname = QObject::tr("D:/KuGou/Joanie Madden - The Immigrant.mp3");
//    QString fname = QObject::tr("D:/KuGou/Joanie Madden - Down By The Salley Gardens.mp3");

//    ID3V1Getter test = ID3V1Getter(fname);
//    DEBUGOUT(test.isId3Valid());
//    DEBUGOUT(test.getGenre());
//    ID3V1_header header = test.getHeader();
//    DEBUGOUT(header.year);
//    DEBUGOUT(header.track[0]);
//    DEBUGOUT(header.genre[0]);
//    DEBUGOUT(header.title);
//    DEBUGOUT(header.artist);

    ID3V2_3Getter test = ID3V2_3Getter(fname);

//    QString x = "sticky question";
//    QString y = "sti";
//    int pos;
//    pos = x.indexOf(y);               // returns 0
//    DEBUGOUT(pos);
//    pos = x.indexOf(y, 1);            // returns 10
//    DEBUGOUT(pos);
//    pos = x.indexOf(y, 10);           // returns 10
//    DEBUGOUT(pos);
//    pos = x.indexOf(y, 11);           // returns -1
//    DEBUGOUT(pos);


    return a.exec();
}
