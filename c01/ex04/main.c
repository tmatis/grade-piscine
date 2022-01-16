#include "header.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a, b;

	a = 42;
	b = 54;
	printf("ft_ultimate_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a(%d), b(%d)\n", a, b);
	a = 2;
	b = 2;
	printf("ft_ultimate_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a(%d), b(%d)\n", a, b);
	a = INT_MAX;
	b = INT_MAX;

	printf("ft_ultimate_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a(%d), b(%d)\n", a, b);

	a = INT_MIN;
	b = INT_MIN;
	printf("ft_ultimate_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a(%d), b(%d)\n", a, b);

	a = 8;
	b = 3;

	printf("ft_ultimate_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a(%d), b(%d)\n", a, b);
	return (0);
}
