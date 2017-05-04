#include "ft_fillit.h"
#include "libft.h"

char	**field_maker(int side)
{
	char	**field;
	char	**start;
	int	i;

	field = (char**)malloc(sizeof(*field) * (side + 1));
	field[side] = NULL;
	start = field;
	i = side;
	while (i--)
	{
		*field = ft_strnew(side);
		*field = ft_memset(*field, '.', side);
		field++;
	}
	return (start);
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

t_tetri	*tetriminos_list_maker(char *input, char c)
{
	t_tetri	*tet_lst;
	int		x;
	int		y;

	x = y = 0;
	tet_lst = NULL;
	while (*input)
	{
		if (*input == '#')
		{
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
