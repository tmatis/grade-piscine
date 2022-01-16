#include "header.h"
#include <stdio.h>

int main(void)
{
	int i = 0;

	printf("before ft_ft: %d\n", i);
	ft_ft(&i);
	printf("after ft_ft: %d\n", i);
	return (0);
}
