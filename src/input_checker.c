/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:28:26 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/03 18:59:36 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_fillit.h"

void	tet_lstadd_back(t_tetri **alst, char c, int x, int y)
{
	t_tetri *new;
	t_tetri *tmp;

	new = (t_tetri*)malloc(sizeof(t_tetri));
	new->c = c;
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_tetri	*tetriminos_list_maker(char *input, char c)
{
	t_tetri	*tet_lst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	tet_lst = NULL;
	while (*input)
	{
		if (*input == '#')
			tet_lstadd_back(&tet_lst, c, x, y);
		if (*input == '\n')
			y++;
		else
			x++;
		if (x == 4)
			x = 0;
		if (y == 5)
		{
			y = 0;
			c++;
		}
		input++;
	}
	return (tet_lst);
}

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

int		tetriminos_checker(char *input)
{
	t_tetri *list;
	t_tetri *head;
	int		connexions;

	list = tetriminos_list_maker(input, 'A');
	head = list;
	connexions = 5;
	while (list)
	{
		list = check_connexions(list, list->c, &connexions);
		if (connexions <= 2)
			return (0);
	}
	return (1);
}

int		input_checker(char *input)
{
	printf("square %d\n", check_file(input));
	printf("tet %d\n", tetriminos_checker(input));
	return (check_file(input) && tetriminos_checker(input));
}
