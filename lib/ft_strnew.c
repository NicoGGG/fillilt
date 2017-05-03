/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:27:48 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/24 19:25:34 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if ((new = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
