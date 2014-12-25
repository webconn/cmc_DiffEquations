#include "test.h"

#include <stdio.h>
#include <math.h>

/* Тестирование решателя дифференциального уравнения первого порядка */
void test_eq(double start, double end, int num_pieces, eq_solver solver, func2 f, func orig, double x0)
{
        struct grid_function *grid = grid_create(start, end, num_pieces);
        solver(grid, f, x0);

        double error = 0;

        for (int i = 0; i <= grid->num_pieces; i++) {
                struct point p = grid_getPoint(grid, i);
                double y_orig = orig(p.x);

                printf("%.4g\t%.4g\t%.4g\n", p.x, p.y, y_orig);

                double c_error = fabs(p.y - y_orig);
                if (c_error > error)
                        error = c_error;
        }

        printf("# Error: %.6g\n", error);
        grid_free(grid);
}

/* Тестирование решателя системы дифференциальных уравнений первого порядка */
void test_sys(double start, double end, int num_pieces, sys_solver solver, func3 f1, func3 f2, func orig1, func orig2, double x0, double y0)
{
        struct grid_function *grid1 = grid_create(start, end, num_pieces);
        struct grid_function *grid2 = grid_create(start, end, num_pieces);

        solver(grid1, grid2, f1, f2, x0, y0);

        double error = 0;

        for (int i = 0; i <= grid1->num_pieces; i++) {
                struct point p1 = grid_getPoint(grid1, i);
                struct point p2 = grid_getPoint(grid2, i);

                double y1_o = orig1(p1.x);
                double y2_o = orig2(p2.x);

                printf("%.4g\t\t%.4g\t%.4g\t\t%.4g\t%.4g\n", p1.x, p1.y, y1_o, p2.y, y2_o);

                double c_error1 = fabs(p1.y - y1_o);
                double c_error2 = fabs(p2.y - y2_o);

                if (c_error2 > c_error1)
                        c_error1 = c_error2;

                if (c_error1 > error)
                        error = c_error1;
        }

        printf("# Error: %.6g\n", error);

        grid_free(grid1);
        grid_free(grid2);
}

/* Тестирование решателя дифференциального уравнения второго порядка */
void test_bound(double start, double end, int num_pieces, func p, func q, func f, struct boundary_start s, func orig)
{
        struct grid_function *grid = grid_create(start, end, num_pieces);
        boundary_solve(grid, p, q, f, s);

        double error = 0;
        for (int i = 0; i <= grid->num_pieces; i++) {
                struct point p = grid_getPoint(grid, i);
                double y_orig = 0;
                if (orig != NULL)
                        y_orig = orig(p.x);

                printf("%.4g\t%.4g\t%.4g\n", p.x, p.y, y_orig);

                double c_error = fabs(p.y - y_orig);
                if (c_error > error)
                        error = c_error;
        }

        if (orig != NULL)
                printf("# Error: %.6g\n", error);

        grid_free(grid);
}
