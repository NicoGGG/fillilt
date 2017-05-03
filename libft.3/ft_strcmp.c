/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:32:29 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/25 19:18:10 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == 0 || *s2 == 0 || *s1 != *s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else
		return (ft_strcmp(s1 + 1, s2 + 1));
}
