/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:48:08 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:30:49 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *scr, size_t n)
{
	int		i;
	char	*dcp;
	char	*scp;

	i = 0;
	dcp = (char *)dst;
	scp = (char *)scr;
	while (n > 0)
	{
		dcp[i] = scp[i];
		n--;
		i++;
	}
	return (dcp);
}
