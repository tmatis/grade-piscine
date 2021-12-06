#include "header.h"
#include <stdio.h>

int main(void)
{
	for (int i = 1; i < 10; i++)
	{
		printf("\n----combn for %i-----\n", i);
		ft_print_combn(i);
	}
}
