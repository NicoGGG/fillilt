/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:31:32 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/03 19:01:35 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "fillit.h"

int		check_new(char *str)
{
	int ch;
	int s;

	ch = 0;
	while (*str)
	{
		if (ch % 4 == 0 && ch != 0 && ch != s)
		{
			s = ch;
			if (*str != 10)
				return (0);
			str++;
		}
		if (ch % 16 == 0 && ch != 0 && *(str + 1))
		{
			if (*str != 10 && *(str + 1) != 10)
				return (0);
			str++;
		}
		if (ch % 4 != 0 || ch == 0 || ch == s)
			ch++;
		str++;
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
	printf("buf : \n%s\n", buf);
	i = input_checker(buf);
	printf("FINAL RESULT : %d\n", i);
	return (0);
}
