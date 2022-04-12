#include <stdlib.h>

unsigned int ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int srclen = ft_strlen(src);
    if (srclen + 1 < n) {
        ft_memcpy(dest, src, srclen + 1);
    } else if (n != 0) {
        ft_memcpy(dest, src, n - 1);
        dest[n - 1] = '\0';
    }
    return srclen;
}