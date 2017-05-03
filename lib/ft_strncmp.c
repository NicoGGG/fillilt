/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:38:05 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/25 19:19:40 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	else if (*s1 != *s2 || *s1 == 0 || *s2 == 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
