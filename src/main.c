/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:37 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/04 14:51:54 by nguelfi          ###   ########.fr       */
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
	int		*coords;
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
	coords = (int*)malloc(2);
	if (!coords || !field)
		return (0);
	coords[0] = 0;
	coords[1] = 0;
	while (!ft_fill_field(coords, t, field))
	{
		printf("TEST\n");
		coords[0] = 0;
		coords[1] = 0;
		field = field_maker(++size);
		if (!field)
			return (0);
	}
	while (*field)
		printf("%s\n", *field++);
	return (0);
}
