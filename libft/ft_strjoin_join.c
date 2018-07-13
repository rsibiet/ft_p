/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:36:54 by rsibiet           #+#    #+#             */
/*   Updated: 2016/03/07 13:45:08 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strjoin_join(char **s, char *c)
{
	int		i;
	char	**s2;

	i = 0;
	while (s[i] != NULL)
		i++;
	s2 = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (s[i] != NULL)
	{
		s2[i] = ft_strdup(s[i]);
		i++;
	}
	s2[i] = ft_strdup(c);
	s2[i + 1] = NULL;
	return (s2);
}
