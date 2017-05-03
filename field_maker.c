#include "include/fillit.h"
#include "include/libft.h"

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

int main(void)
{
	char **field = field_maker(5);
	while (*field)
		printf("%s\n", *field++);
	return (0);
}
