/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:57:11 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:47:32 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int b;
	int l;
	int memo_b;

	b = 0;
	l = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[b] != '\0' && s2[l] != '\0')
	{
		memo_b = b;
		l = 0;
		while (s1[b] == s2[l] && s1[b] != '\0' && s2[l] != '\0')
		{
			b++;
			l++;
		}
		if (s2[l] != '\0')
			b = memo_b + 1;
	}
	if (s2[l] == '\0')
		return ((char *)s1 + memo_b);
	else
		return (NULL);
}
