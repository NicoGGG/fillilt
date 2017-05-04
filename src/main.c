/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:21:37 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/04 14:21:43 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
t_tetri *place_tetriminos(int coords[], 
						char **field, t_tetri *t, t_tetri *head)
{
	int		x;
	int		y;

	if (!t)
	{
		t = (t_tetri*)malloc(sizeof(t_tetri));
		t->c = '$';
		return (t);
	}
	if (t->c != head->c)
		return (t);
	x = t->x - head->x;
	y = t->y - head->y;
	if (field[coords[1] + y] && field[coords[1] + y][coords[0] + x] == '.' && t)
	{
		if ((t = place_tetriminos(coords, field, t->next, head)))
		{
			field[coords[1] + y][coords[0] + x] = head->c;
			return (t);
		}
	}
	return (NULL);
}

int		*coord_mover(int *c, char **field)
{
	c[0]++;
	if (!field[c[1]])
	{
		return (NULL);
	}
	if (!field[c[1]][c[0]])
	{
		c[1]++;
		c[0] = 0;
		return (c);
	}
	return (c);
}

int recursion(int *coords, t_tetri *t, char **field)
{
	int			success;
	t_tetri		*tmp;

	while (!(tmp = place_tetriminos(coords, field, t, t)))
	{
		coords = coord_mover(coords, field);
		if (!coords)
			return (0);
	}
	t = tmp;

	if (!t)
		success = 0;
	if (!t && t->c == '$')
		success = 1;
	if (t && t->c != '$')
	{
		success = recursion(coords, t, field);
	}
	return (success);
}

int		main()
{
	int		size;
	char	*s;
	int		fd;
	int		r;
	char	**field;
	int		*coords;
	t_tetri	*t;

	s = malloc(1000);
	fd = open("sample.fillit", O_RDONLY);
	r = read(fd, s, 900);
	s[r] = '\0';
	t = tetriminos_list_maker(s);
	size = 1;
	field = field_maker(size);
	coords = (int*)malloc(2);
	coords[0] = 0;
	coords[1] = 0;
	while (!recursion(coords, t, field))
	{
		coords[0] = 0;
		coords[1] = 0;
		field = field_maker(++size);
	}
	while (*field)
		printf("%s\n", *field++);

	return (0);
}