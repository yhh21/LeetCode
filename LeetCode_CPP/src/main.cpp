#define DEBUG

#ifdef DEBUG
#include "L1_100/L0084.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0084::Solution)->Test();
#endif /// DEBUG

    return 0;
}