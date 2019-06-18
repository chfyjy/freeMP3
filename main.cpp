#include "widget.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    QString fname = QObject::tr("D:/KuGou/Joanie Madden - Down By The Salley Gardens.mp3");

    ID3V1Getter test = ID3V1Getter(fname);
    DEBUGOUT(test.isId3Valid());
    ID3V1_header header = test.getHeader();

    DEBUGOUT(header.year);
    DEBUGOUT(header.track[0]);
    DEBUGOUT(header.genre[0]);
    DEBUGOUT(header.title);
    DEBUGOUT(header.artist);


    return a.exec();
}
