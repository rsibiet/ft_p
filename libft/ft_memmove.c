/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:48:33 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:32:06 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp;
	char	*dcp;
	char	*scp;

	i = 0;
	dcp = (char *)dst;
	scp = (char *)src;
	temp = (char *)malloc(sizeof(char) * len);
	if (temp == NULL)
		return (NULL);
	while (i < len)
	{
		temp[i] = scp[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dcp[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
