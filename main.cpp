#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //QString fname = QObject::tr("D:/KuGou/July - Beyond The Memory.mp3");


    return a.exec();
}
