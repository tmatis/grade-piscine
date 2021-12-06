#include <unistd.h>
#include <stdio.h>

static int numlen(unsigned int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putnbr(int nb)
{
	char 			buff[15];
	unsigned int	un;
	int				len;
	int				is_neg = 0;

	if (nb < 0)
	{
		buff[0] = '-';
		un = -nb;
		is_neg = 1;
	}
	else
		un = nb;
	len = numlen(un);
	buff[len + is_neg] = '\0';
	while (len)
	{
		buff[len + is_neg - 1] = un % 10 + '0';
		un /= 10;
		len--;
	}
	write(1, buff, ft_strlen(buff));
}
