/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:51:35 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/18 16:13:04 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *prev;
	size_t size;

	tmp = *alst;
	while (tmp)
	{
		prev = tmp;
		size = tmp->content_size;
		del(tmp->content, size);
		tmp = tmp->next;
		free(prev);
	}
	*alst = NULL;
}
