#include "boundary.h"

#include <stdlib.h>

void boundary_solve(struct grid_function *grid, double (*p)(double), double (*q)(double), double (*f)(double), struct boundary_start s)
{
        /* Allocate memory for tridiagonal solver */
        double *alpha = (double *) malloc((grid->num_pieces + 1) * sizeof (double));
        double *beta = (double *) malloc((grid->num_pieces + 1) * sizeof (double));

        /* Compute tridiagonal solver coeffitients */
        double h = (grid->end - grid->start) / grid->num_pieces;
        double x = grid->start;

        /* Calculate start values */
        alpha[0] = -s.gamma[0] / (s.sigma[0] * h - s.gamma[0]);
        beta[0] = s.delta[0] * h / (s.sigma[0] * h - s.gamma[0]);

        /* Calculate tridiagonal coeffitient values */
        for (int i = 1; i <= grid->num_pieces; i++) {
                /* Calculate all required coeffitients */
                double a = 1 / h / h - p(x) / 2 / h;
                double b = 2 / h / h - q(x);
                double c = 1 / h / h + p(x) / 2 / h;
                double d = -f(x);

                /* Calculate current alpha and beta */
                alpha[i] = c / (b - a * alpha[i - 1]);
                beta[i] = (beta[i - 1] * a - d) / (b - a * alpha[i - 1]);

                x += h;
        }

        /* Calculate function values downward, start from the last point */
        
        /* Start point */
        grid->values[grid->num_pieces] = (s.gamma[1] * beta[grid->num_pieces] + s.delta[1] * h) / (s.gamma[1] * (1 - alpha[grid->num_pieces]) + s.sigma[1] * h);

        /* Step process */
        for (int i = grid->num_pieces - 1; i >= 0; i--) {
                grid->values[i] = grid->values[i + 1] * alpha[i + 1] + beta[i + 1];
        }

        /* Free memory */
        free(alpha);
        free(beta);
}
