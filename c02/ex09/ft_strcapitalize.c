static int is_alphanum(char c)
{
	return (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9');
}

static char capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static char lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_alphanum(str[i]))
		{
			if (i == 0 || !is_alphanum(str[i - 1]))
				str[i] = capitalize(str[i]);
			else
				str[i] = lowercase(str[i]);
		}
		i++;
	}
	return (str);
}