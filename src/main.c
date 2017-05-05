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

int		main(int argc, char *argv[])
{
	int		size;
	char	*s;
	int		fd;
	int		r;
	char	**field;
	t_tetri	*t;

	if (argc != 2)
		return (0);
	s = malloc(1000);
	fd = open(argv[1], O_RDONLY);
	r = read(fd, s, 900);
	s[r] = '\0';
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
	while (*field)
		printf("%s\n", *field++);
	return (0);
}
