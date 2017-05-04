#include "fillit.h"

int		valid_tile(char c)
{
	if (!c)
		return (0);
	return (c == '#' || c == '.');
}

int		check_new(char *str)
{
	int i;
	int ch;

	printf("TEST : \n%s\n-----", str);
	ch = 0;
	i = 0;
	while (str[i])
	{
		printf("test\n");
		if (ch % 4 || ch == 0)
		{
			printf("test mod 4\n");
			if (!valid_tile(str[i]))
			{
				printf("ERROR 0");
				return (0);
			}
			i++;
		}
		if (ch % 16 == 0 && ch != 0 && str[i + 1])
		{
			printf("test mod 16\n");
			if (str[i] != '\n' && str[i + 1] != '\n')
			{
				return (0);
			}
			i++;
		}
		if (ch % 4 != 0 || ch == 0)
		{
			ch++;
		}
		i++;
	}
	return (1);
}

int		check_tetr(char **tab)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (tab[i] && i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tab[i][j] == '#')
				count++;
			else if (tab[i][j] != '.')
				return (0);
		}
		if (tab[i][j] == 0)
			i++;
		else
			return (0);
	}
	return (count == 4);
}

int		check_file(char *str)
{
	char	**tab;
	int		i;
	int		r;

	r = check_new(str);
	printf("R square %d\n", r);
	tab = ft_strsplit(str, 10);
	i = 0;
	while (tab[i])
	{
		if ((i + 1) % 4 == 1)
			r *= check_tetr(&tab[i]);
		i++;
	}
	return (r);
}


int		main(int argc, char const **argv)
{
	char	buf[1024];
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	i = read(fd, buf, 1024);
	i = check_file(buf);
	printf("square %d\n", i);
	return (0 * argc);
}
