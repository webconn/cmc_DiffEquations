#include "functions.h"

#include <math.h>

// start point 0, 10

double f1(struct point p)
{
        return (double) sin(p.x) - p.y;
}

double orig1(double x)
{
        return (-cos(x) + sin(x) + 21 * exp(-x)) / 2;
}

// start point 0, 0

double f0(struct point p)
{
        return (double) (3 - p.y - p.x);
}

double orig0(double x)
{
        return (double) (4 - x - 4 * exp(-x));
}

// start point 0, 10

double f2(struct point p)
{
        return (double) -p.y - p.x * p.x;
}

double orig2(double x)
{
        return (double) - x * x + 2 * x - 2 + 12 * exp(-x);
}
