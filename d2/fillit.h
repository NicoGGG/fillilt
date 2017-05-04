#ifndef	FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#          include <stdio.h>

typedef struct	s_tetri
{
	char			c;
	int				x;
	int				y;
	struct s_tetri	*next;
}				t_tetri;

int			input_checker(char *input);
char		**ft_strsplit(char const *s, char c);
t_tetri		*tetriminos_list_maker(char *input, char c);
char		**field_maker(int side);
#endif
