#define DEBUG

#ifdef DEBUG
#include "L1_100/L0077.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0077::Solution)->Test();
#endif /// DEBUG

    return 0;
}