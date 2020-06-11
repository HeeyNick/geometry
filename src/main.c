#include "operation.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

figure circle[100];
int main()
{
    size_t number = read_file("figures.txt", circle);
    if (number == 0) {
        printf("Invalid data\n");
        return 0;
    }
    for (int i = 0; i < number; i++) {
        printf("%d. circle (%d, %d , %d)\n",
               i + 1,
               circle[i].x,
               circle[i].y,
               circle[i].r);
        printf("\tperimeter = %.3lf\n", perim_of_circle(circle, i));
        printf("\tarea = %.3lf\n", aria_of_circle(circle, i));
        crossing_check(circle, i, number);
    }
    return 0;
}
