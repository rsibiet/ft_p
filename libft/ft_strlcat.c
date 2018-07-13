/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:33:10 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:41:10 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	while (dst[i1] != '\0' && i1 < size)
		i1++;
	while (src[i2] != '\0' && i1 < size - 1)
	{
		dst[i1] = src[i2];
		i1++;
		i2++;
	}
	if (i1 < size)
		dst[i1] = '\0';
	while (src[i2] != '\0')
	{
		i1++;
		i2++;
	}
	return (i1);
}
