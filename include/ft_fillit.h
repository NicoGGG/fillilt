/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:11:47 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/03 19:11:56 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include      <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_tetri
{
	char			c;
	int				x;
	int				y;
	struct s_tetri	*next;
}				t_tetri;

int		check_tetr(char **tab);
int		check_file(char *str);
int		check_new(char *str);
int		intput_checker(char *input);
int		square_checker(char *input);
int		tetriminos_checker(char *str);
t_tetri	*check_connexions(t_tetri *list, char c, int *connexions);
t_tetri	*tetriminos_list_maker(char *input, char c);
char	**field_maker(int side);
int		ft_fill_field(int *coords, t_tetri *t, char **field);

#endif
