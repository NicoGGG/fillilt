#include "../include/ft_fillit.h"

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