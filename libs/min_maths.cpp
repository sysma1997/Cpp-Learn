#include "min_maths.h"

int sum(int x, int y)
{
    return x + y;
}
int substract(int x, int y)
{
    return x - y;
}

int multiplication(int x, int y)
{
    return x * y;
}
int divition(int x, int y)
{
    if (x == 0 || y == 0)
        return 0;

    return x / y;
}