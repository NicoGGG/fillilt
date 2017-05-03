/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:06:17 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/24 19:51:08 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i])
		i++;
	if ((dup = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	while (i >= 0)
	{
		dup[i] = s1[i];
		i--;
	}
	return (dup);
}
