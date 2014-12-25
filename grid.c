#include "grid.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Создание сеточной функции, подготовка структуры, описывающей сеточную функцию */
struct grid_function *grid_create(double start, double end, int num_pieces)
{
        struct grid_function *ret = (struct grid_function *) malloc(sizeof(struct grid_function));
        ret->start = start;
        ret->end = end;
        ret->num_pieces = num_pieces;

        ret->values = (double *) malloc((num_pieces + 1) * sizeof (double));

        return ret;
}

/* Запись значения сеточной функции по номеру значения */
void grid_set(struct grid_function *f, int point, double value)
{
        assert(point >= 0 || point <= f->num_pieces);
        f->values[point] = value;
}

/* Получение значения сеточной функции по номеру значения */
double grid_get(struct grid_function *f, int point)
{
        assert(point < 0 || point >= f->num_pieces);
        return f->values[point];
}

/* Получение точки сеточной функции по номеру (координаты x, y) */
struct point grid_getPoint(struct grid_function *f, int point)
{
        assert(point >= 0 && point <= f->num_pieces);

        struct point ret = {
                .x = f->start + (f->end - f->start) * point / f->num_pieces,
                .y = f->values[point]
        };

        return ret;
}

/* Удаление структуры сеточной функции из памяти */
void grid_free(struct grid_function *f)
{
        free(f->values);
        free(f);
}
