#ifndef INCLUDE_GRID_H
#define INCLUDE_GRID_H

struct grid_function {
        double start;           /**< start of segment */
        double end;             /**< end of segment */
        int num_pieces;         /**< number of points */
        double *values;         /**< values */
};

struct point {
        double x;
        double y;
};

struct grid_function *grid_create(double start, double end, int num_pieces);
void grid_set(struct grid_function *f, int point, double value);
double grid_get(struct grid_function *f, int point);
struct point grid_getPoint(struct grid_function *f, int elem);
void grid_free(struct grid_function *f);

#endif
