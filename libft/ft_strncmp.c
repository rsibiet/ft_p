/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:55:19 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:43:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*scp1;
	unsigned char	*scp2;

	i = 0;
	scp1 = (unsigned char *)s1;
	scp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (scp1[i] == scp2[i] && i < n)
	{
		if (scp1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n && scp1[i] == '\0')
		return (0);
	return (scp1[i] - scp2[i]);
}
