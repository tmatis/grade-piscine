#include "header.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void test_number(int n)
{
	dprintf(1, "ft_putnbr(%d) => ", n);
	ft_putnbr(n);
	dprintf(1, "\n");
}

int main(void)
{
	for (int i = -100000; i < 100000; i++)
		test_number(i);
	
	test_number(INT_MAX);
	test_number(INT_MIN);
}
