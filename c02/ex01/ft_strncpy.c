char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	if (n != 0)
	{
		char *d = dest;
		const char *s = src;

		do
		{
			if ((*d++ = *s++) == 0)
			{
				while (--n != 0)
					*d++ = 0;
				break;
			}
		} while (--n != 0);
	}
	return (dest);
}