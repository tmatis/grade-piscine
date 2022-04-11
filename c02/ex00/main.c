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

void test_strcpy(char *str, int is_heap) {
	char *dest = malloc(sizeof(char) * (strlen(str) + 1));

	printf("ft_strcpy(\"%s\") -> \"%s\"\n", str, ft_strcpy(dest, str));
	printf("others infos:\n dest: %s\n str: %s\n", dest, str);
	free(dest);
	if (is_heap)
		free(str);
}

int main(void) {
	srand(0);

	test_strcpy("", false);
	test_strcpy("a", false);
	test_strcpy("hello world", false);
	test_strcpy("lorum ipsum dolor sit amet", false);

	for (size_t i = 10; i <= 100; i++)
		test_strcpy(random_string(i), true);
}