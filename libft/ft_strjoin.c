/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:53:52 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:40:46 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*cc;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	cc = (char *)malloc(sizeof(*s1) * (i + j + 1));
	if (cc == NULL)
		return (NULL);
	cc = ft_strcpy(cc, s1);
	cc = ft_strcat(cc, s2);
	return (cc);
}
