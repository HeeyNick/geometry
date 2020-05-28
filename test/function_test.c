#include "operation.h"
#include <ctest.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265358979323846
figure circle[100];

void create_circle(figure* circle, int n, int p1, int p2, double p3)
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

CTEST(perim_of_circle, test_1)
{
    create_circle(circle, 1, 1, 2, 3);
    double expect = 2 * PI * 3;
    double result = perim_of_circle(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}

CTEST(aria_of_circle, test_2)
{
    create_circle(circle, 1, 2, 2, 2);
    double expect = PI * 2 * 2;//12,56
    double result = aria_of_circle(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}
CTEST(crossing, cross_figure)
{
    create_circle(circle, 1, 2, 2, 2);
    create_circle(circle, 2, 4, 2, 1);
    int expend = 1 ;
    double result = crossing(circle, 1, 2);
    ASSERT_EQUAL(expend , result);
}
CTEST(crossing, not_cross_figure)
{
    create_circle(circle, 1, 2, 2, 2);
    create_circle(circle, 2, 6, 2, 1);
    int expend = 0 ;
    double result = crossing(circle, 1, 2);
    ASSERT_EQUAL(expend , result);
}
