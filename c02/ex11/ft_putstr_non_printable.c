#include <unistd.h>

static void put_hex(unsigned char c) {
	char *hex = "0123456789abcdef";

	write(1, "\\", 1);
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

static int is_printable(unsigned char c) {
	return (c >= 32 && c <= 126);
}

void ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_printable(str[i]))
			put_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}