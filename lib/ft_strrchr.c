/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:03:05 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/14 15:20:15 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	t;
	int		i;

	i = 0;
	tmp = (char *)s;
	t = (char)c;
	while (tmp[i])
		i++;
	while (i >= 0)
	{
		if (tmp[i] == t)
			return (&tmp[i]);
		else
			i--;
	}
	return (NULL);
}
