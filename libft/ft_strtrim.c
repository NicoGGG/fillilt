/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:20:19 by nguelfi           #+#    #+#             */
/*   Updated: 2017/05/02 16:13:10 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#define SPACE(i) s[i] == ' ' || s[i] == '\n' || s[i] == '\t'

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*trim;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (SPACE(i))
		i++;
	j = i;
	while (s[j])
		j++;
	while ((SPACE(j) || s[j] == 0) && s[i])
		j--;
	k = j - i;
	if (!(trim = ft_memalloc(k + 2)))
		return (NULL);
	trim[k++] = 0;
	while (--k >= 0)
	{
		trim[k] = s[j];
		j--;
	}
	return (trim);
}
