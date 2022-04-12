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

int main(void) {
	srand(0);

	ft_putstr_non_printable("");
	ft_putstr_non_printable("abc");
	ft_putstr_non_printable("ABCDEFGHIKLMOPQRSTUVXYZ");
	ft_putstr_non_printable("abc\n123");
	ft_putstr_non_printable("abc\n123def");
	ft_putstr_non_printable("\n\n\n\n\a\xff");
}