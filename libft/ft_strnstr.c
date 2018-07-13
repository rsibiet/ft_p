/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:56:22 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:45:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	memo_b;

	b = 0;
	l = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s2[l] != '\0' && s1[b] != '\0' && b < len)
	{
		memo_b = b;
		l = 0;
		while (s1[b] == s2[l] && s1[b] != '\0' && s2[l] != '\0' && b < len)
		{
			b++;
			l++;
		}
		if (l != len && s2[l] != '\0')
			b = memo_b + 1;
	}
	if (l == len || s2[l] == '\0')
		return ((char *)&s1[memo_b]);
	else
		return (NULL);
}
