/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:48:45 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:32:28 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*bcp;

	i = 0;
	bcp = (unsigned char *)b;
	while (len > 0)
	{
		bcp[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (bcp);
}
