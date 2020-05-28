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

CTEST(area, test_1)
{
    create_circle(circle, 1, 1, 2, 2);
    double expect = 4 * M_PI;
    double result = area(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}
CTEST(crossing, crossed_figures)
{
    create_circle(circle, 1, 1, 2, 2);
    create_circle(circle, 2, 2, 2, 2);
    int expect = 1;
    int result = crossing(circle, 1, 2);
    ASSERT_EQUAL(expect, result);
}

CTEST(crossing, not_crossed_figures)
{
    create_circle(circle, 1, 1, 2, 2);
    create_circle(circle, 2, 7, 8, 2);
    int expect = 0;
    int result = crossing(circle, 1, 2);
    ASSERT_EQUAL(expect, result);
}
CTEST(parse_coord, correct_x)
{
    char* line = "circle (1 2, 3)\n";
    size_t expect = 0;
    size_t i = 8;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(parse_coord, incorrect_x)
{
    char* line = "circle (a 2, 3)\n";
    size_t expect = 1;
    size_t i = 8;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(parse_coord, correct_y)
{
    char* line = "circle (1 2, 3)\n";
    size_t expect = 0;
    size_t i = 10;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}

CTEST(parse_coord, incorrect_y)
{
    char* line = "circle (1 b, 3)\n";
    size_t expect = 1;
    size_t i = 10;
    size_t result = parse_coord(&i, &circle[0].x, line);
    ASSERT_EQUAL(expect, result);
}