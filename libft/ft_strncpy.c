/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:55:39 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:44:15 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while (j < i && j < len)
	{
		dst[j] = src[j];
		j++;
	}
	if (i == j && j < len)
		dst[j] = '\0';
	while (j < len)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
