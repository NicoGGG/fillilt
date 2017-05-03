/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:10:58 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/03 19:11:40 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				input_checker(char *input);
char			**ft_strsplit(char const *s, char c);
#endif
