/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:54:42 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:42:31 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cp;

	i = 0;
	while (s[i] != '\0')
		i++;
	cp = (char *)malloc(sizeof(cp) * i + 1);
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cp[i] = (*f)(i, s[i]);
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
