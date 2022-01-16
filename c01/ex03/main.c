#include "header.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int a, b, div, mod;

	a = 42;
	b = 54;
	printf("ft_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("div(%d), mod(%d)\n", div, mod);
	a = 2;
	b = 2;
	printf("ft_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("div(%d), mod(%d)\n", div, mod);

	a = INT_MAX;
	b = INT_MAX;
	printf("ft_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("div(%d), mod(%d)\n", div, mod);

	a = INT_MIN;
	b = INT_MIN;
	printf("ft_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("div(%d), mod(%d)\n", div, mod);

	a = INT_MAX;
	b = INT_MIN;
	printf("ft_div_mod(a(%d), b(%d)) -> ", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("div(%d), mod(%d)\n", div, mod);
}
