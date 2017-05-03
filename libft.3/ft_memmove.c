/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:34:44 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/02 16:06:46 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (destination - source > 0)
	{
		destination += n - 1;
		source += n - 1;
		while (n--)
			*destination-- = *source--;
	}
	else
	{
		while (n--)
			*destination++ = *source++;
	}
	return (dst);
}
