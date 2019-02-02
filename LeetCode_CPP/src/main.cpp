#define DEBUG

#ifdef DEBUG
#include "L1_100/L0091.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0091::Solution)->Test();
#endif /// DEBUG

    return 0;
}