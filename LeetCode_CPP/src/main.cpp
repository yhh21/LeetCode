#define DEBUG
#ifdef DEBUG
#include "L201_300/L0300.h"
#include "L301_400/L0329.h"
#endif /// DEBUG

int main()
{
#ifdef DEBUG
    (new L0329::Solution)->Test();
#endif /// DEBUG

    return 0;
}