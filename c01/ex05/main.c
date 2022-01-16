#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define true 1
#define false 0

/*
** this function generate a random string of length n
** and return it as a char pointer
*/
char *random_string(size_t n)
{
	char *str = malloc(n + 1);
	size_t i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = (char)(rand() % (126 - 33) + 33);
		i++;
	}
	str[i] = '\0';
	return (str);
}

void test_string(char *str, int is_heap)
{
	printf("ft_putstr(\"%s\") -> ", str);
	fflush(stdout);
	ft_putstr(str);
	printf("\n");
	fflush(stdout);
	if (is_heap)
		free(str);
}

int main(void)
{
	// setup seed for random number generator
	srand(0);
	
	// test basic strings
	test_string("", false);
	test_string("a", false);
	test_string("hello world", false);
	test_string("lorum ipsum dolor sit amet", false);

	// test random strings from size 10 to 1000
	for (size_t i = 10; i <= 1000; i++)
		test_string(random_string(i), true);
}
