#define DEBUG
#ifdef DEBUG
#include "L101_200/L0200.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0200::Solution)->Test();
#endif /// DEBUG

    return 0;
}