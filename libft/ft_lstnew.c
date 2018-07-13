/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:51:32 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:55:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cnt;

	new = NULL;
	cnt = (void *)content;
	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->content = cnt;
		if (content == NULL)
			new->content_size = 0;
		else
			new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
