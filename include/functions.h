#ifndef INCLUDE_FUNCTIONS_H
#define INCLUDE_FUNCTIONS_H

#include "grid.h"
#include "boundary.h"

double f2(struct point p);
double orig2(double x);

double f1(struct point p);
double orig1(double x);

double f0(struct point p);
double orig0(double x);

/* Boundary functions */
extern struct boundary_start bstart0;
double bp0(double x);
double bq0(double x);
double bf0(double x);
double borig0(double x);

extern struct boundary_start bstart1;
double bp1(double x);
double bq1(double x);
double bf1(double x);
double borig1(double x);

extern struct boundary_start bstart2;
double bp2(double x);
double bq2(double x);
double bf2(double x);
double borig2(double x);

// Task
extern struct boundary_start bstart3;
double bp3(double x);
double bq3(double x);
double bf3(double x);

#endif
