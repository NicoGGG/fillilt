/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:08:26 by nguelfi           #+#    #+#             */
/*   Updated: 2017/04/25 21:23:06 by nguelfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*copy;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	copy = f(lst);
	head = copy;
	if (head == NULL)
		return (NULL);
	while (lst->next)
	{
		if ((copy->next = malloc(sizeof(t_list))) == NULL)
			return (NULL);
		if ((copy->next->content = malloc(lst->content_size)) == NULL)
			return (NULL);
		lst = lst->next;
		copy->next = f(lst);
		if (copy->next == NULL)
			return (NULL);
		copy = copy->next;
	}
	return (head);
}
