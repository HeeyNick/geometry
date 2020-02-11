#include <stdio.h>

double square (int a, int b)
{
	double sqr = (3,14 * (b*b));
	return sqr;
}


int main()
{
	double sqr = 0;
	sqr = square(0,13);
	printf("%f", sqr);
	return 0;
}
