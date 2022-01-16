#include "header.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a = 0;
	int b = 0;

	printf("ft_swap(a(%d), b(%d)) -> ", a, b);
	ft_swap(&a, &b);
	printf("a(%d), b(%d)\n", a, b);
	a = 42;
	printf("ft_swap(a(%d), a(%d)) -> ", a, a);
	ft_swap(&a, &a);
	printf("a(%d)\n", a);
	a = 42;
	b = 54;
	printf("ft_swap(a(%d), b(%d)) -> ", a, b);
	ft_swap(&a, &b);
	printf("a(%d), b(%d)\n", a, b);

	a = INT_MAX;
	b = INT_MIN;
	printf("ft_swap(a(%d), b(%d)) -> ", a, b);
	ft_swap(&a, &b);
	printf("a(%d), b(%d)\n", a, b);
	return (0);
}
