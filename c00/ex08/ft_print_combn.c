#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int n)
{
	char c = '0' + n;
	write(1, &c, 1);
}

void print_tab(int tab[10], int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		if (tab[i - 1] >= tab[i])
			return;
		i++;
	}
	i = 0;
	while (i < size)
		ft_putnbr(tab[i++]);
	if (tab[0] < (10 - size))
		write(1, ", ", 2);
}

void handle_one(void)
{
	int tab[10];
	int i;

	tab[0] = 0;
	i = 0;
	while (i < 10)
	{
		print_tab(tab, 1);
		tab[0] = ++i;
	}
}

// for n = 2
// 01, 02, 03, ..., 09, 12, ..., 79, 89

void ft_print_combn(int n)
{
	int tab[10];
	int i;

	if (n < 0 || n >= 10)
		return;
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	if (n == 1)
	{
		handle_one();
		return ;
	}
	while (tab[0] <= (10 - n))
	{
		print_tab(tab, n);
		tab[n - 1]++;
		i = n;
		while (i)
		{
			i--;
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
		}
	}
}
