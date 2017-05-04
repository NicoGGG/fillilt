/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:31:32 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/04 12:37:17 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_tetri	*check_connexions(t_tetri *list, char c, int *connexions)
{
	t_tetri	*head;

	head = list;
	*connexions = 0;
	while (head && head->c == c)
	{
		list = head->next;
		while (list && list->c == c)
		{
			if (head->x == list->x && head->y == list->y - 1)
				(*connexions)++;
			if (head->x == list->x - 1 && head->y == list->y)
				(*connexions)++;
			list = list->next;
		}
		head = head->next;
	}
	return (head);
}

int		tetriminos_checker(char *str)
{
	t_tetri *list;
	int		connexions;

	list = tetriminos_list_maker(str, 'A');
	connexions = 5;
	while (list)
	{
		list = check_connexions(list, list->c, &connexions);
		if (connexions <= 2)
			return (0);
	}
	return (1);
}

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
