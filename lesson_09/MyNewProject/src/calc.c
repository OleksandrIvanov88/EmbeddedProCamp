#include "calc.h"
#include "rules.h"
int calc_add(int a, int b)
{
    if (rules_is_addition_allowed())
    {
        return a + b;
    }
    return 0;
}