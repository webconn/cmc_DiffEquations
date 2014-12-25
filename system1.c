#include "systems.h"

#include <math.h>

// start point 0, 0.25, 1

double f1_1(double t, double x, double y)
{
        return cos(t + 1.1 * y) + x;
}

double f1_2(double t, double x, double y)
{
        return -y * y + 2.1 * x + 1.1;
}

// start point 0, 3, 1

double fs0_1(double t, double x, double y)
{
        return x + y;
}

double fs0_2(double t, double x, double y)
{
        return x + y;
}

double x0_orig(double t)
{
        return 1 + 2 * exp(2 * t);
}

double y0_orig(double t)
{
        return -1 + 2 * exp(2 * t);
}
