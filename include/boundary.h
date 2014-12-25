#ifndef INCLUDE_BOUNDARY_H
#define INCLUDE_BOUNDARY_H

#include "grid.h"

/* Описание краевых условий уравнения по формуле из отчёта */
struct boundary_start {
        double sigma[2];
        double gamma[2];
        double delta[2];
};

void boundary_solve(struct grid_function *grid, double (*p)(double), double (*q)(double), double (*f)(double), struct boundary_start start);

#endif
