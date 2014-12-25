#include "functions.h"

#include "boundary.h"

#include <math.h>

// test 0, start point 0, end point 1
struct boundary_start bstart0 = {
        .sigma = { 1, 1 },
        .gamma = { -1, 0 },
        .delta = { 0, 3.718 }
};

double bp0(double x)
{
        return -2 * x;
}

double bq0(double x)
{
        return -2;
}

double bf0(double x)
{
        return 4 * x;
}

double borig0(double x)
{
        return x + exp(x * x);
}

// test 1, start point 0, end point 1
struct boundary_start bstart1 = {
        .sigma = { 1, 1 },
        .gamma = { 1, 0 },
        .delta = { 1, 0 }
};

double bp1(double x)
{
        return 1;
}

double bq1(double x)
{
        return -2;
}

double bf1(double x)
{
        return 0;
}

double borig1(double x)
{
        return -(exp(3 - 2 * x) - exp(x)) / (2 + exp(3));
}

// test 3, start point 0, end point 1
struct boundary_start bstart2 = {
        .sigma = { 0, 1 },
        .gamma = { 1, 0 },
        .delta = { 1, 1 }
};

double bp2(double x)
{
        return 0;
}

double bq2(double x)
{
        return 0;
}

double bf2(double x)
{
        return -sin(x);
}

double borig2(double x)
{
        return 2 * x - sin(x) - 1 + sin(1);
}

// test #14, start point 0.5, end point 0.8

struct boundary_start bstart3 = {
        .sigma = { 2, 1 },
        .gamma = { -1, 0 },
        .delta = { 1, 3 }
};

double bp3(double x)
{
        return 2 * x * x;
}

double bq3(double x)
{
        return 1;
}

double bf3(double x)
{
        return -x;
}
