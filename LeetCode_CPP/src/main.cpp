#define DEBUG

#ifdef DEBUG
#include "L1_100/L0062.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0062::Solution)->Test();
#endif /// DEBUG

    return 0;
}