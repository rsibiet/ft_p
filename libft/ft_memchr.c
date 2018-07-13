/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:47:45 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:30:05 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scp;
	unsigned char	ccp;

	i = 0;
	ccp = (unsigned char)c;
	scp = (unsigned char *)s;
	while (n > 0)
	{
		if (scp[i] == ccp)
			return ((void *)s + i);
		i++;
		n--;
	}
	return (NULL);
}
