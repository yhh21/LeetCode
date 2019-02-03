#define DEBUG

#ifdef DEBUG
#include "L1_100/L0093.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0093::Solution)->Test();
#endif /// DEBUG

    return 0;
}