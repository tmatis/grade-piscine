#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

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

void test_str_is_uppercase(char *str)
{
	int ret = ft_str_is_uppercase(str);

	printf("str_is_uppercase(\"%s\") == %d\n", str, ret);
}

int main(void)
{
	srand(0);

	test_str_is_uppercase("");
	test_str_is_uppercase("abc");
	test_str_is_uppercase("ABCDEFGHIKLMOPQRSTUVXYZ");
	test_str_is_uppercase("abc123");
	test_str_is_uppercase("abc123def");
	test_str_is_uppercase("123456789");
	test_str_is_uppercase("456A");
	test_str_is_uppercase("a456a");

	for (int i = 1; i < 100; i++)
	{
		char *str = random_string(i);
		test_str_is_uppercase(str);
		free(str);
	}
}