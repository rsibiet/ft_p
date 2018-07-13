/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:02:42 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 14:24:15 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_new;
	t_list	*tmp;

	begin_new = ft_lstnew(lst->content, lst->content_size);
	begin_new = (*f)(lst);
	if (begin_new == NULL)
		return (NULL);
	tmp = begin_new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		new = (*f)(lst);
		if (new == NULL)
			return (NULL);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (begin_new);
}
