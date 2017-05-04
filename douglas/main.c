#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
t_tetri *place_tetriminos(int coords[], 
						char **field, t_tetri *t, t_tetri *head)
{
	int		x;
	int		y;
	t_tetri	*done;

	if (!t)
	{
		done = (t_tetri*)malloc(sizeof(t_tetri));
		done->c = '$';
		return (done);
	}
	if (t->c != head->c)
		return (t);
	x = t->x - head->x;
	y = t->y - head->y;
	if (field[coords[1] + y][coords[0] + x] == '.')
	{
		if ((t = place_tetriminos(coords, field, t->next, head)))
		{
			field[coords[1] + y][coords[0] + x] = '#';
			return (t);
		}
	}
	return (NULL);
}

int		main()
{
	char *s = malloc(1000);
	int fd = open("sample.fillit", O_RDONLY);
	int r = read(fd, s, 900);
	s[r] = '\0';
	// printf("%d\n", input_checker(s));
	t_tetri		*t = tetriminos_list_maker(s);
	char **field = field_maker(10);
	int *coords = (int*)malloc(2);
	coords[0] = 0;
	coords[1] = 0;
	field[2][0] = '#';
	place_tetriminos(coords, field, t, t);
	while (*field)
		printf("%s\n", *field++);

	return (0);
}