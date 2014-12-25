#include "runge-kutta.h"

#include <assert.h>

#include "grid.h"

/* Решение дифференциального уравнения первого порядка методом Рунге-Кутта второго порядка точности */
void runge_kutta_2(struct grid_function *grid, double (*f)(struct point), double start)
{
        double h = (grid->end - grid->start) / grid->num_pieces;

        for (int i = 0; i <= grid->num_pieces; i++) {
                if (i == 0) {
                        /* Задание начального значения сеточной функции */
                        grid->values[0] = start;
                } else {
                        /* Подсчёт точек предиктора и корректора */
                        struct point p_predict = grid_getPoint(grid, i - 1);
                        struct point p_correct = p_predict;
                        
                        double correct = grid->values[i - 1] + f(p_predict) * h;
                        p_correct.y = correct;
                        p_correct.x += h;

                        /* Вычисление текущего значения сеточной функции */
                        /* Формула для вычисления следующего значения:
                         * y[i+1] = y[i] + ( f (x[i], y[i]) + f (x[i], p[i]) ) * h / 2,
                         * где p[i] = y[i] + f (x[i], y[i]) * h
                         */
                        grid->values[i] = grid->values[i - 1] + (f(p_predict) + f(p_correct)) * h / 2;
                }
        }
}

/* Решение дифференциального уравнения первого порядка методом Рунге-Кутта четвёртого порядка точности */
void runge_kutta_4(struct grid_function *grid, double (*f)(struct point), double start)
{
        double h = (grid->end - grid->start) / grid->num_pieces;

        for (int i = 0; i <= grid->num_pieces; i++) {
                if (i == 0) {
                        /* Задание начального значения сеточной функции */
                        grid->values[0] = start;
                } else {

                        struct point p_predict = grid_getPoint(grid, i - 1);
                        double k1 = f(p_predict);
                        double k2 = f((struct point) { .x = p_predict.x + h / 2, .y = p_predict.y + k1 * h / 2 });
                        double k3 = f((struct point) { .x = p_predict.x + h / 2, .y = p_predict.y + k2 * h / 2 });
                        double k4 = f((struct point) { .x = p_predict.x + h, .y = p_predict.y + k3 * h});

                        /* Формула для вычисления следующего значения сеточной функции представлена ниже */
                        grid->values[i] = grid->values[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6;
                }
        }
}

/* Решение системы дифференциальных уравнений первого порядка методом Рунге-Кутта второго порядка точности */
void runge_kutta_system2(struct grid_function *grid1, struct grid_function *grid2, double (*f1)(double, double, double), double (*f2)(double, double, double), double start1, double start2)
{
        /* Проверка совместимости двух сеточных функций */
        assert(grid1->num_pieces == grid2->num_pieces);
        assert(grid1->start == grid2->start);
        assert(grid2->end == grid2->end);

        double h = (grid1->end - grid1->start) / grid1->num_pieces;
        
        for (int i = 0; i <= grid1->num_pieces; i++) {
                if (i == 0) {
                        /* Задание начальных значений сеточных функций */
                        grid1->values[0] = start1;
                        grid2->values[0] = start2;
                } else {
                        struct point p_predict = grid_getPoint(grid1, i - 1);
                        struct point p_correct = p_predict;

                        double correct = grid1->values[i - 1] + f1(p_predict.x, p_predict.y, grid2->values[i - 1]) * h;
                        p_correct.y = correct;

                        /* Формулы для вычисления значений сеточных функций приведены в отчёте */
                        grid1->values[i] = grid1->values[i - 1] + (f1(p_predict.x, p_predict.y, grid2->values[i - 1]) + f1(p_correct.x, p_correct.y, grid2->values[i - 1])) * h / 2;

                        p_predict = grid_getPoint(grid2, i - 1);
                        p_correct = p_predict;

                        correct = grid2->values[i - 1] + f2(p_predict.x, grid1->values[i - 1], p_predict.y) * h;
                        p_correct.y = correct;

                        grid2->values[i] = grid2->values[i - 1] + (f2(p_predict.x, grid1->values[i - 1], p_predict.y) + f2(p_correct.x, grid1->values[i - 1], p_correct.y)) * h / 2;
                }
        }
}
