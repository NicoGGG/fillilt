/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:57:17 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/13 19:54:44 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	t;
	char	*tmp;

	t = (char)c;
	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == t)
			return (tmp);
		else
			tmp++;
	}
	if (t == 0)
		return (tmp);
	return (NULL);
}
