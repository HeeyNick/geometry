#include "readfile.h"
#include <math.h>
#include <stdio.h>

double perim_of_circle(figure* circle, int i)
{
    double pi = 3.14159265358979323846;
    double perim = 2 * pi * circle[i].r;
    return (perim);
}
double aria_of_circle(figure* circle, int i)
{
    double pi = 3.14159265358979323846;
    double aria = (pi * circle[i].r * circle[i].r);
    return (aria);
}

int crossing(figure* circle, size_t n, int i)
{
    if ((sqrt(pow(circle[n].x - circle[i].x, 2)
              + pow(circle[n].y - circle[i].y, 2)))
        <= (circle[n].r + circle[i].r)) {
        return 1;
    }
    return 0;
}

void crossing_check(figure* circle, size_t n, size_t number)
{
    int tmp = 0;
    for (int i = 0; i < number; i++) {
        if (i != n) {
            if (crossing(circle, n, i) == 1) {
                if (tmp == 0) {
                    printf("\tintersects:\n");
                }
                tmp = 1;
                printf("\t\t%d. circle\n", i + 1);
            }
        }
    }
}
