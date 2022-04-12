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

int random_int(int min, int max)
{
	return rand() % (max - min) + min;
}

void print_memory(char *str, size_t n)
{
	size_t i;

	i = 0;
	while (i <= n)
	{
		printf("%2x ", (unsigned char)str[i]);
		i++;
	}
	printf(": %s\n", str);
}

void test_ft_strlcpy(char *str, int size, int is_heap, int minus)
{
	char *dest = malloc(sizeof(char) * (size + 1));

	memset(dest, 0x42, size);
	dest[size] = '\0';

	if (dest == NULL)
		return;

	int ret = ft_strlcpy(dest, str, size - minus);
	printf("ret: %d\n", ret);
	printf("dest: ");
	print_memory(dest, size);
	if (is_heap)
		free(str);
	free(dest);
}

int main(void)
{
	srand(0);

	test_ft_strlcpy("", 0, false, 0);
	test_ft_strlcpy("", 4, false, 0);
	test_ft_strlcpy("a", 1, false, 0);
	test_ft_strlcpy("hello world", 11, false, 0);
	test_ft_strlcpy("lorum ipsum dolor sit amet", 20, false, 0);
	test_ft_strlcpy("lorum ipsum dolor sit amet", 30, false, 10);

}