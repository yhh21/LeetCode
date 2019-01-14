#define DEBUG

#ifdef DEBUG
#include "L1_100/L0075.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0075::Solution)->Test();
#endif /// DEBUG

    return 0;
}