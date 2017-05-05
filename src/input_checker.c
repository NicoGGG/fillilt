#include "ft_fillit.h"

int		valid_tile(char c)
{
	if (!c)
		return (0);
	return (c == '#' || c == '.');
}

int		square_checker(char *input)
{
	int		new_line;
	int		tile;

	tile = 0;
	new_line = 0;
	while (*input)
	{
		tile++;
		while (tile % 5)
		{
			tile++;
			if (!valid_tile(*input++))
				return (0);
		}
		if (*input++ != '\n')
			return (0);
		new_line++;
		if (*input && new_line % 4 == 0 && *input++ != '\n')
			return (0);
	}
	if (new_line % 4 != 0)
		return (0);
	if (*(input - 2) == 10)
		return (0);
	return (1);
}

t_tetri		*check_connexions(t_tetri *list, char c, int *connexions)
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
	if (!(list))
		return (0);
	while (list)
	{
		list = check_connexions(list, list->c, &connexions);
		if (connexions <= 2 || connexions > 4)
			return (0);
	}
	return (1);
}
