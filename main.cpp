#include "widget.h"
#include "metadatageter.h"
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    QString fname = QObject::tr("D:/KuGou/Joanie Madden - Down By The Salley Gardens.mp3");

    MetaDataGeter testgeter = MetaDataGeter(fname);

    return a.exec();
}
