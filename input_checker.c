#include "fillit.h"

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
	return (1);
}

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

t_tetri	*tetriminos_list_maker(char *input)
{
	t_tetri	*tet_lst;
	int		x;
	int		y;
	char	c;

	x = y = 0;
	c = 'A';
	tet_lst = NULL;
	while (*input)
	{
		if (*input == '#')
		{
		printf("%c, input %c, x %d, y %d\n", c, *input, x, y);
			tet_lstadd_back(&tet_lst, c, x, y);
			
		}
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

t_tetri		*check_connexions(t_tetri *list, char c, int *connexions)
{
	t_tetri	*head;

	head = list;
	*connexions = 0;
	while (head && head->c == c)
	{
		list = head->next;
		printf("head %c %d %d\n", head->c, head->x, head->y);
		while (list && list->c == c)
		{
			if (head->x == list->x && head->y == list->y - 1)
				(*connexions)++;
			if (head->x == list->x - 1 && head->y == list->y)
				(*connexions)++;
			printf("list %c %d %d\n", list->c, list->x, list->y);
			list = list->next;
		}
		head = head->next;
	}
	printf("%c %d\n", c, *connexions);
	return (head);
}

int		tetriminos_checker(char *input)
{
	t_tetri *list;
	t_tetri *head;
	int		connexions;

	list = tetriminos_list_maker(input);
	head = list;
	connexions = 5;
	while (list)
	{
		// printf("return %c, %d, %d, %d, %d\n", list->c, list->x, list->y, 
		// list->next->x, list->next->y);
		list = check_connexions(list, list->c, &connexions);
		printf("conn %d\n", connexions);
		if (connexions <= 2)
			return (0);
	}
	return (1);
}

int		input_checker(char *input)
{
	printf("square %d\n", square_checker(input));
	printf("tet %d\n", tetriminos_checker(input));
	return (0);
}