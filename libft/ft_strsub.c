/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:57:29 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:48:05 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	size_t	i;

	i = 0;
	cp = (char *)malloc(sizeof(*s) * len + 1);
	if (cp == NULL)
		return (NULL);
	while (i < len)
	{
		cp[i] = s[start];
		start++;
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
