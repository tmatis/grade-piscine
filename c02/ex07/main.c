#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

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

void test_ft_strupcase(char *str)
{
	char *ret = ft_strupcase(str);

	printf("sft_strupcase(\"%s\") == %s\n", ret, str);
	free(str);
}

int main(void)
{
	srand(0);

	test_ft_strupcase(strdup(""));
	test_ft_strupcase(strdup("abc"));
	test_ft_strupcase(strdup("ABCDEFGHIKLMOPQRSTUVXYZ"));
	test_ft_strupcase(strdup("abc123"));
	test_ft_strupcase(strdup("abc123def"));
	test_ft_strupcase(strdup("123456789"));
	test_ft_strupcase(strdup("456A"));
	test_ft_strupcase(strdup("a456a"));

	for (int i = 1; i < 100; i++)
	{
		char *str = random_string(i);
		test_ft_strupcase(str);
	}
}