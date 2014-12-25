#ifndef INCLUDE_TEST_H
#define INCLUDE_TEST_H

#include "grid.h"
#include "boundary.h"

typedef double (*func)(double);
typedef double (*func2)(struct point);
typedef double (*func3)(double, double, double);
typedef void (*eq_solver)(struct grid_function *, func2, double);
typedef void (*sys_solver)(struct grid_function *, struct grid_function *, func3, func3, double, double);

void test_eq(double start, double end, int num_pieces, eq_solver solver, func2 f, func answer, double x0);
void test_sys(double start, double end, int num_pieces, sys_solver solver, func3 f1, func3 f2, func answer1, func answer2, double x0, double y0);
void test_bound(double start, double end, int num_pieces, func p, func q, func f, struct boundary_start s, func orig);

#endif
