#ifndef INCLUDE_RUNGE_KUTTA_H
#define INCLUDE_RUNGE_KUTTA_H

#include "grid.h"

void runge_kutta_2(struct grid_function *grid, double (*f)(struct point), double start);
void runge_kutta_4(struct grid_function *grid, double (*f)(struct point), double start);
void runge_kutta_system2(struct grid_function *grid1, struct grid_function *grid2, double (*f1)(double, double, double), double (*f2)(double, double, double), double start1, double start2);

#endif
