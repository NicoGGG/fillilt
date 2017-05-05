/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:37 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/04 15:08:44 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"

void	print_field(char **field)
{
	int i;

	i = 0;
	while (field[i])
	{
		ft_putendl(field[i]);
		i++;
	}
}

char	*ft_read(char *arg)
{
	int		fd;
	int		r;
	char	*s;

	if ((s = malloc(sizeof(char) * 600)) == NULL)
		return (NULL);
	fd = open(arg, O_RDONLY);
	r = read(fd, s, 600);
	s[r] = 0;
	return (s);
}

int		main(int argc, char *argv[])
{
	int		size;
	char	*s;
	char	**field;
	t_tetri	*t;

	if (argc != 2)
		return (0);
	s = ft_read(argv[1]);
	t = tetriminos_list_maker(s, 'A');
	size = 1;
	field = field_maker(size);
	if (!(square_checker(s) && tetriminos_checker(s)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	while (!ft_fill_field(field, t, t))
	{
		free(field);
		field = field_maker(++size);
		if (!field)
			return (0);
	}
	print_field(field);
	return (0);
}
