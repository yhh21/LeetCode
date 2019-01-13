#define DEBUG

#ifdef DEBUG
#include "L1_100/L0073.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0073::Solution)->Test();
#endif /// DEBUG

    return 0;
}