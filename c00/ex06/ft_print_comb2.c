#include <unistd.h>
#include <stdio.h>


void ft_putnbr(int nb)
{
	char c;

	if (nb >= 10)
	{
		c = nb / 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = '0';
		write(1, &c, 1);
	}
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putnbr(i);
			write(1, " ", 1);
			ft_putnbr(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
