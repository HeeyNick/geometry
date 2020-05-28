#include "props.h"
#include <ctest.h>
#include <stdio.h>
#define N 1000

figure circle[N];

void create_circle(figure* circle, size_t n, int p1, int p2, double p3)
{
    circle[n].x = p1;
    circle[n].y = p2;
    circle[n].r = p3;
    circle[n].name[0] = 'c';
    circle[n].name[1] = 'i';
    circle[n].name[2] = 'r';
    circle[n].name[3] = 'c';
    circle[n].name[4] = 'l';
    circle[n].name[5] = 'e';
    circle[n].name[6] = '\0';
}

CTEST(perimeter, test_1)
{
    create_circle(circle, 1, 1, 2, 1.5);
    double expect = 3 * M_PI;
    double result = perimeter(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}