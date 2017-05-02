#include "ft_fillit.h"

int		check_new(char *str)
{
	int i;
	int ch;
	int s;

	printf("TEST : \n%s\n-----", str);
	ch = 0;
	i = 0;
	while (str[i])
	{
		printf("test\n");
		if (ch % 4 == 0 && ch != 0 && ch != s)
		{
			s = ch;
			printf("test mod 4\n");
			if (str[i] != 10)
			{
				printf("i = %d, ch = %d, str[i] = %c, str[i + 1] = %c\n", i, ch, str[i], str[i + 1]);
				return (0);
			}
			i++;
		}
		if (ch % 16 == 0 && ch != 0 && str[i + 1])
		{
			printf("test mod 16\n");
			if (str[i] != 10 && str[i + 1] != 10)
			{
				printf("i = %d, ch = %d, str[i] = %c, str[i + 1] = %c\n", i, ch, str[i], str[i + 1]);
				return (0);
			}
			i++;
		}
		if (ch % 4 != 0 || ch == 0 || ch == s)
		{
			printf("TEST CH ET S %d et %d\n", ch, s);
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
	printf("fd = %d\n", fd);
	i = read(fd, buf, 1024);
	printf("i = %d , buf : \n%s\n", i, buf);
	i = check_file(buf);
	printf("%d\n", i);
	return 0;
}