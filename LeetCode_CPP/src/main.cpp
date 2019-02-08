#define DEBUG

#ifdef DEBUG
#include "L101_200/L0120.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0120::Solution)->Test();
#endif /// DEBUG

    return 0;
}