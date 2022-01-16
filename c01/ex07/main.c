#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

/*
** this function generate a random int table of length n
** and return it as int pointer
** number range is from -1000000 to 1000000
*/
int *random_int_tab(int n)
{
	int *tab = malloc(n * sizeof(int));
	int i;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tab[i] = rand() % (1000000 - -1000000) + -1000000;
		i++;
	}
	return (tab);
}

void print_tab(int *tab, size_t size)
{
	size_t i;

	if (!tab)
	{
		printf("null");
		return;
	}

	i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf("]");
}

void test_int_tab(int *tab, int size, int is_heap)
{
	printf("ft_rev_int_tab(");
	print_tab(tab, size);
	printf(", %d) -> ", size);
	ft_rev_int_tab(tab, size);
	print_tab(tab, size);
	printf("\n");
	if (is_heap)
		free(tab);
}


int main(void)
{
	// setup seed for random number generator
	srand(0);

	int tab[] = {0};
	int tab_empty[] = {};

	test_int_tab(tab_empty, 0, false);
	test_int_tab(NULL, 0, false);
	test_int_tab(tab, 1, false);

	// test from size 1 to 1000

	for (int i = 1; i <= 1000; i++)
		test_int_tab(random_int_tab(i), i, true);
	
}
