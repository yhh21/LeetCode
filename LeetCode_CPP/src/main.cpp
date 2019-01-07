#define DEBUG

#ifdef DEBUG
#include "L1_100/L0052.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0052::Solution)->Test();
#endif /// DEBUG

    return 0;
}