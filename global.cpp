#include "global.h"

int getScreenWidth()
{
    return  QApplication::desktop()->screenGeometry().width();
}
int getScreenHeight()
{
    return  QApplication::desktop()->screenGeometry().height();
}
