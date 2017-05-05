/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:11:47 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/05 17:17:20 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
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

int				intput_checker(char *input);
int				square_checker(char *input);
int				tetriminos_checker(t_tetri *list);
t_tetri			*check_connexions(t_tetri *list, char c, int *connexions);
t_tetri			*tetriminos_list_maker(char *input, char c);
char			**field_maker(int side);
int				ft_fill_field(char **field, t_tetri *t, t_tetri *head);

#endif
