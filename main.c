/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:37 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/12 21:26:19 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"

static void	print_field(char **field)
{
	int i;

	i = 0;
	while (field[i])
	{
		ft_putendl(field[i]);
		i++;
	}
}

static char	*ft_read(char *arg)
{
	int		fd;
	int		r;
	char	*s;

	if ((s = malloc(sizeof(char) * 600)) == NULL)
		return (NULL);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	r = read(fd, s, 600);
	if (r < 0)
		return (NULL);
	s[r] = 0;
	return (s);
}

static void	free_field(char **field)
{
	int	i;

	i = 0;
	while (field[i])
		free(field[i++]);
	free(field);
}

int			print_usage(void)
{
	write(1, "usage: fillit file\n", 19);
	return (1);
}

int			main(int argc, char *argv[])
{
	int		size;
	char	*s;
	char	**field;
	t_tetri	*t;

	if (argc != 2)
		return (print_usage());
	s = ft_read(argv[1]);
	t = (s) ? tetriminos_list_maker(s, 'A') : NULL;
	size = 1;
	field = field_maker(size);
	if (!field || !t || (!(square_checker(s) && tetriminos_checker(t))))
		return (7 - write(1, "error\n", 6));
	while (!ft_fill_field(field, t, t))
	{
		free_field(field);
		field = field_maker(++size);
		if (!field)
			return (0);
	}
	print_field(field);
	return (0);
}
