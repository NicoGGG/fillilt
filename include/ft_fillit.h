/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:11:47 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/09 14:14:34 by dengstra         ###   ########.fr       */
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

t_tetri			*tetriminos_list_maker(char *input, char c);
char			**field_maker(int side);
int				square_checker(char *input);
int				ft_fill_field(char **field, t_tetri *t, t_tetri *head);
int				tetriminos_checker(t_tetri *list);

#endif
