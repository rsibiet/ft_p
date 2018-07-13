/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:47:58 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:30:22 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	i = 0;
	s1cp = (unsigned char *)s1;
	s2cp = (unsigned char *)s2;
	while (n > 0)
	{
		if (s1cp[i] == s2cp[i])
			i++;
		else
			return (s1cp[i] - s2cp[i]);
		n--;
	}
	return (0);
}
