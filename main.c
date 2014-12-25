#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "grid.h"
#include "test.h"
#include "runge-kutta.h"
#include "functions.h"
#include "systems.h"

void test1_rk2(void)
{
        printf("# Testing equation 1, Runge-Kutta, double precision\n");
        test_eq(0, 2, 400, runge_kutta_2, f0, orig0, 0);
}

void test1_rk4(void)
{
        printf("# Testing equation 1, Runge-Kutta, quad precision\n");
        test_eq(0, 2, 400, runge_kutta_4, f0, orig0, 0);
}

void test2_rk2(void)
{
        printf("# Testing equation 2, Runge-Kutta, double precision\n");
        test_eq(0, 2, 400, runge_kutta_2, f1, orig1, 10);
}

void test2_rk4(void)
{
        printf("# Testing equation 2, Runge-Kutta, quad precision\n");
        test_eq(0, 2, 400, runge_kutta_4, f1, orig1, 10);
}

void test3_rk2(void)
{
        printf("# Testing equation 3, Runge-Kutta, double precision\n");
        test_eq(0, 2, 400, runge_kutta_2, f2, orig2, 10);
}

void test3_rk4(void)
{
        printf("# Testing equation 3, Runge-Kutta, quad precision\n");
        test_eq(0, 2, 400, runge_kutta_4, f2, orig2, 10);
}

void test4(void)
{
        printf("# Testing system of equations 1, Runge-Kutta, double precision\n");
        test_sys(0, 2, 400, runge_kutta_system2, fs0_1, fs0_2, x0_orig, y0_orig, 3, 1);
}

void test5(void)
{
        printf("# Testing system of equations 2, Runge-Kutta, double precision\n");
        test_sys(0, 2, 400, runge_kutta_system2, f1_1, f1_2, x0_orig, y0_orig, 0.25, 1);
}

void test6(void)
{
        printf("# Testing boundary problem 1\n");
        test_bound(0, 1, 1000, bp0, bq0, bf0, bstart0, borig0);
}

void test7(void)
{
        printf("# Testing boundary problem 2\n");
        test_bound(0, 1, 1000, bp1, bq1, bf1, bstart1, borig1);
}

void test8(void)
{
        printf("# Testing boundary problem 3\n");
        test_bound(0, 1, 1000, bp2, bq2, bf2, bstart2, borig2);
}

void test9(void)
{
        printf("# Testing boundary problem 4\n");
        test_bound(0.5, 0.8, 300, bp3, bq3, bf3, bstart3, NULL);
}

int main(int argc, char *argv[])
{
        if (argc < 2) {
                fprintf(stderr, "Usage: %s test_id\n", argv[0]);
                exit(-1);
        }

        int test_id = atoi(argv[1]);

        switch (test_id) {
                case 1:
                        test1_rk2();
                        break;
                case 2:
                        test1_rk4();
                        break;
                case 3:
                        test2_rk2();
                        break;
                case 4:
                        test2_rk4();
                        break;
                case 5:
                        test3_rk2();
                        break;
                case 6:
                        test3_rk4();
                        break;
                case 7:
                        test4();
                        break;
                case 8:
                        test5();
                        break;
                case 9:
                        test6();
                        break;
                case 10:
                        test7();
                        break;
                case 11:
                        test8();
                        break;
                case 12:
                        test9();
                        break;
        }

        return 0;
}
