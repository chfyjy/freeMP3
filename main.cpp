#include "widget.h"
#include "ffmpeg.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    cout << "Hello FFmpeg!" << endl;
    av_register_all();
    unsigned version = avcodec_version();
    cout << "version is:" << version << endl;


    return 0;
}
