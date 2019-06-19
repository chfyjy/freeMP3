#include "mediatag.h"


int getBit(char c, int bnum)
{
    return c & 1 << bnum;
}
