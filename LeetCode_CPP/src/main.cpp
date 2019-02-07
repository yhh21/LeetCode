#define DEBUG

#ifdef DEBUG
#include "L101_200/L0106.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0106::Solution)->Test();
#endif /// DEBUG

    return 0;
}