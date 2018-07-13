/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:47:31 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:29:47 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*dcp;
	unsigned char	*scp;
	unsigned char	ccp;

	i = 0;
	dcp = (unsigned char *)dst;
	scp = (unsigned char *)src;
	ccp = (unsigned char)c;
	while (n > 0 && scp[i] != ccp)
	{
		dcp[i] = scp[i];
		i++;
		n--;
	}
	if (n > 0)
		return (dcp + i + 1);
	return (NULL);
}
