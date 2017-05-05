/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:44:25 by dengstra          #+#    #+#             */
/*   Updated: 2017/05/04 15:15:09 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		place_tetriminos(int xy[], char **field, t_tetri *t, t_tetri *head)
{
	int		x;
	int		y;

	if (!t || t->c != head->c)
		return (1);
	x = t->x - head->x;
	y = t->y - head->y;
	if (field[xy[1] + y] && field[xy[1] + y][xy[0] + x] == '.' && t)
	{
		if (place_tetriminos(xy, field, t->next, head))
		{
			field[xy[1] + y][xy[0] + x] = head->c;
			return (1);
		}
	}
	return (0);
}

int		*xy_mover(int *xy, char **field)
{
	if (!field[xy[1]])
		return (NULL);
	xy[0]++;
	if (!field[xy[1]][xy[0]])
	{
		xy[1]++;
		xy[0] = 0;
		return (xy);
	}
	return (xy);
}

void	cleaner(char **field, char c)
{
	int x;
	int y;

	y = 0;
	while (field[y])
	{
		x = 0;
		while (field[y][x])
		{
			if (field[y][x] == c)
				field[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		ft_fill_field(char **field, t_tetri *t, t_tetri *h)
{
	int *xy;

	if (!t)
		return (1);
	xy = (int*)malloc(sizeof(int) * 4);
	xy[0] = 0;
	xy[1] = 0;
	while (xy)
	{
		if (place_tetriminos(xy, field, t, t))
		{
			if (ft_fill_field(field, t->next->next->next->next, h))
				return (1);
			else
				cleaner(field, t->c);
		}
		xy = xy_mover(xy, field);
	}
	return (0);
}